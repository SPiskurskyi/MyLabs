#include <iostream>
#include <ctime>
#include <iomanip>

template<class T>
class matrix
{
public:
	matrix()
	{
		_array = new T * [1];
		_array[0] = new T[1];
		_columns = _rows = 1;
	}
	matrix(size_t __rows, size_t __columns) : _rows(__rows), _columns(__columns)
	{
		_array = new T * [_rows];
		for (size_t i = 0; i < _rows; ++i)
			_array[i] = new T[_columns];
	}
	~matrix()
	{
	}
	void shuffle(int left_border, int right_border)
	{
		for (int i = 0; i < _rows; ++i)
		{
			for (int j = 0; j < _columns; ++j)
				_array[i][j] = left_border + rand() % right_border;
		}
	}
	T at(int __i, int __j) const
	{
		return _array[__i][__j];
	}
	void set(int __i, int __j, T _value)
	{
		_array[__i][__j] = _value;
	}
	size_t get_rows() const
	{
		return _rows;
	}
	size_t get_columns() const
	{
		return _columns;
	}
	void print()
	{
		for (int i = 0; i < _rows; ++i)
		{
			for (int j = 0; j < _columns; ++j)
				std::cout << std::setw(4) << _array[i][j] << " ";
			std::cout << "\n";
		}
	}
	matrix<T> operator*(matrix<T>& m)
	{
		matrix<T> res_matrix(this->_rows, m._columns);
		for (size_t i = 0; i < res_matrix._rows; ++i)
		{
			for (size_t j = 0; j < res_matrix._columns; ++j)
			{
				res_matrix.set(i, j, 0);
				for (size_t t = 0; t < this->_columns; ++t)
					res_matrix.set(i, j, res_matrix.at(i, j) + this->at(i, t) * m.at(t, j));
			}
		}
		return res_matrix;
	}
private:
	T** _array;
	size_t _rows;
	size_t _columns;
};
int main()
{
	srand(time(NULL));
	matrix<int> A(5, 4);
	A.shuffle(0, 10);
	matrix<int> B(4, 5);
	B.shuffle(0, 3);
	std::cout << "\tMATRIX A " << std::endl;
	A.print();
	std::cout << std::endl;
	std::cout << "\tMATRIX B " << std::endl;
	B.print();
	matrix<int> C;
	C = A * B;
	std::cout << std::endl;
	std::cout << "\tMATRIX C = A * B" << std::endl;
	C.print();
}