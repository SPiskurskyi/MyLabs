#include <stdio.h>
#include <stdlib.h>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <intrin.h> // Windows
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#include <x86intrin.h> // Linux
#else
#   error "Unknown compiler"
#endif
#include <math.h> 
#include <time.h>

#define NANOSECONDS_PER_SECOND_NUMBER 1000000000 

#define A  50
#define B  30
#define C  10
#define D  5
#define E  2.5
#define F  2.5
#define G  5
#define H  5

#pragma GCC push_options
#pragma GCC optimize ("no-unroll-loops")

#define REPEAT_COUNT 1000000
#define REPEATOR(count, code) \
for (unsigned int indexIteration = (count); indexIteration--;){ code; }
#define TWO_VALUES_SELECTOR(variable, firstValue, secondValue) \
	(variable) = indexIteration % 2 ? (firstValue) : (secondValue);

double getCurrentTime() {
	clock_t time = clock();
	if (time != (clock_t)-1) {
		return ((double)time / (double)CLOCKS_PER_SEC);
	}
	return 0.; // else 	
}

#pragma GCC push_options
#pragma GCC target ("no-sse2")
//__attribute__((__target__("no-sse2")))
void run_native(double* const dArr) {
	double* const dAC = dArr;
	double* const dA = &dAC[0];
	double* const dC = &dAC[1];
	double* const dB = &dAC[2];
	double* const dD = &dAC[3];
	double* const dE = &dAC[4];
	double* const dF = &dAC[5];
	double* const dG = &dAC[6];
	double* const dH = &dAC[7];

	double* const dResult = &dArr[8];
	double* const dX1 = &dResult[0];

	REPEATOR(REPEAT_COUNT,

		TWO_VALUES_SELECTOR(*dA, 4., A);
	TWO_VALUES_SELECTOR(*dB, 3., B);
	TWO_VALUES_SELECTOR(*dC, 1., C);
	TWO_VALUES_SELECTOR(*dD, 4., D);
	TWO_VALUES_SELECTOR(*dE, 3., E);
	TWO_VALUES_SELECTOR(*dF, 3., F);
	TWO_VALUES_SELECTOR(*dG, 1., G);
	TWO_VALUES_SELECTOR(*dH, 1., H);

	(*dX1) = ((*dA - *dB) - (*dC - *dD) + (*dE + *dF) - (*dG + *dH)); );
}
#pragma GCC pop_options

void run_SSE2(double* const dArr) {
	double* const dAC = dArr;
	double* const dA = &dAC[0];
	double* const dC = &dAC[1];
	double* const dB = &dAC[2];
	double* const dD = &dAC[3];
	double* const dE = &dAC[4];
	double* const dF = &dAC[5];
	double* const dG = &dAC[6];
	double* const dH = &dAC[7];

	double* const dResult = &dArr[8];
	double* const dX1 = &dResult[0];
	__m128d r__zero_zero, r__c_a, r__uORb_b, r__uORb_a, r__a_b, r__c_d, r__e_f, r__g_h, r__temp1, r__temp2, r__result;

	r__zero_zero = _mm_set_pd(0., 0.); // init

	REPEATOR(REPEAT_COUNT,
		TWO_VALUES_SELECTOR(*dA, 4., A);
	TWO_VALUES_SELECTOR(*dB, 3., B);
	TWO_VALUES_SELECTOR(*dC, 1., C);
	TWO_VALUES_SELECTOR(*dD, 4., D);
	TWO_VALUES_SELECTOR(*dE, 3., E);
	TWO_VALUES_SELECTOR(*dF, 3., F);
	TWO_VALUES_SELECTOR(*dG, 1., G);
	TWO_VALUES_SELECTOR(*dH, 1., H);

	r__c_a = _mm_load_pd(dAC);

	r__uORb_a = _mm_load1_pd(dA); // load a
	r__uORb_b = _mm_load1_pd(dB); // ;pad b
	r__a_b = _mm_sub_pd(r__uORb_a, r__uORb_b); // a-b 

	r__uORb_a = _mm_load1_pd(dC); // load c
	r__uORb_b = _mm_load1_pd(dD); // load d
	r__c_d = _mm_sub_pd(r__uORb_a, r__uORb_b); // c-d


	r__uORb_a = _mm_load1_pd(dE); // load e
	r__uORb_b = _mm_load1_pd(dF); // load f
	r__e_f = _mm_add_pd(r__uORb_a, r__uORb_b); // e+f 


	r__uORb_a = _mm_load1_pd(dG); // load g
	r__uORb_b = _mm_load1_pd(dH); // load h
	r__g_h = _mm_add_pd(r__uORb_a, r__uORb_b); // g+h 

	r__temp1 = _mm_sub_pd(r__a_b, r__c_d); // a-b - c-d
	r__temp2 = _mm_sub_pd(r__e_f, r__g_h); // e+f - g+h
	r__result = _mm_add_pd(r__temp1, r__temp2);  // y = ...

	_mm_store_pd(dResult, r__result); // save result
	);
}

void printResult(char* const title, double* const dArr, unsigned int runTime) {
	double* const dAC = dArr;
	double* const dA = &dAC[0];
	double* const dC = &dAC[1];
	double* const dB = &dAC[2];
	double* const dD = &dAC[3];
	double* const dE = &dAC[4];
	double* const dF = &dAC[5];
	double* const dG = &dAC[6];
	double* const dH = &dAC[7];

	double* const dResult = &dArr[8];
	double* const dX1 = &dResult[0];

	printf("%s:\r\n", title);
	printf("x = %f (%f - %f) - (%f - %f) + (%f + %f) - (%f + %f);\r\n", *dX1, *dA, *dB, *dC, *dD, *dE, *dF, *dG, *dH);
	printf("run time: %dns\r\n\r\n", runTime);
}

int main() {
	double* const dArr = (double*)_mm_malloc(9 * sizeof(double), 16);
	if (!dArr) {
		return 0;
	}

	double* const dAC = dArr;
	double* const dA = &dAC[0];
	double* const dC = &dAC[1];
	double* const dB = &dAC[2];
	double* const dD = &dAC[3];
	double* const dE = &dAC[4];
	double* const dF = &dAC[5];
	double* const dG = &dAC[6];
	double* const dH = &dAC[7];

	double* const dResult = &dArr[8];
	double* const dX1 = &dResult[0];

	double startTime, endTime;

	// native (only x86, if auto vectorization by compiler is off) 
	startTime = getCurrentTime();
	run_native(dArr);
	endTime = getCurrentTime();
	printResult((char*)"x86",
		dArr,
		(unsigned int)((endTime - startTime) * (NANOSECONDS_PER_SECOND_NUMBER / REPEAT_COUNT)));

	// SSE2
	startTime = getCurrentTime();
	run_SSE2(dArr);
	endTime = getCurrentTime();
	printResult((char*)"SSE2",
		dArr,
		(unsigned int)((endTime - startTime) * (NANOSECONDS_PER_SECOND_NUMBER / REPEAT_COUNT)));

	_mm_free(dArr);

	printf("Press Enter to continue . . .");
	(void)getchar();
	return 0;
}

#pragma GCC pop_options