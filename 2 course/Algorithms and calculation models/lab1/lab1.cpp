#pragma once

#include <cstdio>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 32
#define DATA_TYPE volatile unsigned long long int 
#define N1 18
#define N2 27

#define sort bulbSort
//#define sort insertSort

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define REPEAT_COUNT 1000000
#define REPEATOR(count, code) \
for (unsigned int indexIteration = (count); indexIteration--;){ code; } 


void bulbSort(int* array, int leftIndex, int rightIndex) {
	int index, temp;
	if (!array) return;
	++rightIndex;
	while (leftIndex < --rightIndex) {
		for (index = leftIndex; index < rightIndex; ++index) {
			if (array[index] > array[index + 1])
			{
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
			}
		}
	}
}
	void insertSort(int* array, int leftIndex, int rightIndex) {
		int iIndex, jIndex;
		for (iIndex = leftIndex + 1; iIndex <= rightIndex; ++iIndex) {
			int temp = array[iIndex];
			jIndex = iIndex - 1;
			for (; jIndex >= leftIndex && array[jIndex] > temp; --jIndex)
			{
				array[jIndex + 1] = array[jIndex];
			}
			array[jIndex + 1] = temp;
		}
	}
	void printVector(void* data, int count) {
		int index = 0;
		for (index = 0; (!count || index < count) && index < DATA_SIZE; index++) {
			printf("%d ", ((int*)data)[index]);
		}
		printf("\n");
	}

	double getCurrentTime() { 
		clock_t time = clock();
		if (time != (clock_t)-1) {
			return ((double)time / (double)CLOCKS_PER_SEC);
		}
		return 0.;
	}
	DATA_TYPE f1_GCD(DATA_TYPE variableN1, DATA_TYPE variableN2) {
		DATA_TYPE returnValue = 1;

		for (DATA_TYPE i = 1, k = MIN(variableN1, variableN2); i <= k; i++) {
			if (!(variableN1 % i || variableN2 % i)) {
				returnValue = i;
			}
		}
		return returnValue;
	}
	DATA_TYPE f2_GCD(DATA_TYPE a, DATA_TYPE b) {
		for (DATA_TYPE aModB; 
			aModB = a % b, a = b, 
			b = aModB;);
		return a;
	}
	DATA_TYPE f3_GCD(DATA_TYPE a, DATA_TYPE b) {
		if (!b) {
			return a;
		}
		return f3_GCD(b, a % b);
	}


	int main()
	{
		int data[DATA_SIZE] = { 1, 10, 26, 66, 
		23, 30, 9, 58, 47, 36, 52, 43, 18, 77,
		15, 64, 67, 8, 87, 94, 82, 22, 33, 88,
		70, 6, 5, 45, 3, 2, 0, 91 };
		printf("Sort line: ");		
		sort(data, 0, DATA_SIZE - 1);
		printVector(data, 0);
		DATA_TYPE a = MAX(N1, N2), b = MIN(N1, N2), returnValue;
		double startTime, endTime;		

		startTime = getCurrentTime();
		REPEATOR(REPEAT_COUNT, returnValue = f1_GCD(a, b););
		endTime = getCurrentTime();
		printf("\nf1_GCD return %lld \r\nrun time: %dns\r\n\r\n", returnValue,
			(unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));

		startTime = getCurrentTime();
		REPEATOR(REPEAT_COUNT, returnValue = f2_GCD(a, b););
		endTime = getCurrentTime();
		printf("f2_GCD return %lld \r\nrun time: %dns\r\n\r\n", returnValue,
			(unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));

		startTime = getCurrentTime();
		REPEATOR(REPEAT_COUNT, returnValue = f3_GCD(a, b););
		endTime = getCurrentTime();
		printf("f3_GCD return %lld \r\nrun time: %dns\r\n\r\n", returnValue,
			(unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));

		printf("Press Enter to continue . . ."); 
		(void)getchar();
		return 0;
	}
