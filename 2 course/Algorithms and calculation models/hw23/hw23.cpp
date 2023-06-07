//#include <vector> // not used !
#include <iostream>
#include <iomanip>

#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

#define EQUATIONS_COUNT 3

#define COEFFICIENTS \
7.0, 1.0, -1.0,\
3.0, 2.0, -5.0,\
3.0, -1.0, 5.0,

#define CONSTANT_TERMS \
2.0,\
1.0,\
2.0

//#define DEBUG // uncomment to debug

using namespace boost::numeric::ublas;

#define DECL_VALUES_ARRAY(NAME, SIZE, ...)\
double arr_##NAME[SIZE] = { __VA_ARGS__ };\
std::vector<double> NAME;\
NAME.assign(arr_##NAME, arr_##NAME + SIZE);
typedef matrix<double, row_major, std::vector<double>> Matrix;
typedef vector<double, std::vector<double>> Vector;

void printMatrix(const std::string& text, Matrix& printingMatrix) {
	std::cout << text << "[" << printingMatrix.size1() << "]" << "[" << printingMatrix.size2() << "](" << std::endl;
	for (unsigned int iIndex = 0; iIndex < printingMatrix.size1(); ++iIndex) {
		std::cout << "( ";
		for (unsigned int jIndex = 0; jIndex < printingMatrix.size2(); ++jIndex) {
			std::cout << printingMatrix(iIndex, jIndex) << " ";
		}
		std::cout << ")," << std::endl;
	}

	std::cout << ")" << std::endl << std::endl;
}

void printEquationsSystem(const std::string& text, Matrix& printingMatrix, Vector& printingVector) {
	std::cout << text << "{" << std::endl;
	for (unsigned int iIndex = 0; iIndex < printingMatrix.size1(); ++iIndex) {
		unsigned char printedPrev = 0;
		for (unsigned int jIndex = 0; jIndex < printingMatrix.size2(); ++jIndex) {
			double elementValue = printingMatrix(iIndex, jIndex);
			if (jIndex && printedPrev) {
				if (elementValue > 0) {
					std::cout << " + ";
				}
				else if (elementValue < 0) {
					std::cout << " - ";
				}
				//else{} // nothing
			}
			if (elementValue > 0 || (!printedPrev && elementValue)) { // ( ... && ... ) - added for removing clang warning
				if (elementValue != -1. && elementValue != 1.) {
					std::cout << printingMatrix(iIndex, jIndex) << "*";
				}
				std::cout << "X" << jIndex + 1;// << " ";
				printedPrev = ~0;
			}
			else if (printingMatrix(iIndex, jIndex) < 0) {
				if (elementValue != -1.) {
					std::cout << -printingMatrix(iIndex, jIndex) << "*";
				}
				std::cout << "X" << jIndex + 1;// << " ";
				printedPrev = ~0;
			}
			//else{} // nothing
		}
		std::cout << " = " << printingVector(iIndex) << ";" << std::endl;
	}

	std::cout << "}" << std::endl << std::endl;
}

void printSolutionSet(const std::string& text, Vector& printingVector) {
	std::cout << text << "{" << std::endl;
	for (unsigned int index = 0; index < printingVector.size(); ++index) {
		unsigned char printedPrev = 0;
		std::cout << "X" << index + 1 << " = " << printingVector(index) << ";" << std::endl;
	}

	std::cout << "}" << std::endl << std::endl;
}

Matrix invertMatrix(const Matrix& matrixA) {
	Matrix copyMatrixA(matrixA);
	//permutation_matrix<decltype(copyMatrixA)::size_type> permutationMatrixA(copyMatrixA.size1()); // ? // only for C++11	
	permutation_matrix<Matrix::size_type> permutationMatrixA(copyMatrixA.size1());
	size_t res = lu_factorize(copyMatrixA, permutationMatrixA);
	if (res != 0) {
		throw std::logic_error("lu_factorize error");
	}

	Matrix inverseMatrixA(identity_matrix<double>(copyMatrixA.size1())); // Identity matrix
	lu_substitute(copyMatrixA, permutationMatrixA, inverseMatrixA);

	return inverseMatrixA;
}

int main(int argc, char** argv) {
	try {
		std::cout << std::fixed;

		// A
		DECL_VALUES_ARRAY(matrixA_values, EQUATIONS_COUNT * EQUATIONS_COUNT, COEFFICIENTS);
		Matrix matrixA(EQUATIONS_COUNT, EQUATIONS_COUNT, matrixA_values);

		// b
		DECL_VALUES_ARRAY(vectorB_values, EQUATIONS_COUNT, CONSTANT_TERMS);
		Vector vectorB(EQUATIONS_COUNT, vectorB_values);

		// A^-1
		auto invertedMatrixA = invertMatrix(matrixA);

		// x = A^-1 * b
		Vector vectorX = prod(invertedMatrixA, vectorB);

#ifdef DEBUG
		printMatrix("matrixA: ", matrixA);
		std::cout << "vectorB: " << vectorB << std::endl << std::endl;
		printMatrix("invertedMatrixA: ", invertedMatrixA);
		std::cout << "vectorX: " << vectorX << std::endl << std::endl;
#endif
		printEquationsSystem("System of equations: ", matrixA, vectorB);
		printSolutionSet("Solving system of equations: ", vectorX);
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

#ifdef __linux__ 
	std::cout << "Press any key to continue . . . " << std::endl;
	(void)getchar();
#elif defined(_WIN32)    
	system("pause");
#else
#endif

	return 0;
}