#include <stdio.h>
#include <stdlib.h>

#define BLOCK_COUNT 4
#define BLOCK_SIZE 1024
#define DATA_SIZE (BLOCK_COUNT * BLOCK_SIZE)

int compareFunction(const void* a, const void* b) {
	const int* arg1 = (const int*)a;
	const int* arg2 = (const int*)b;

	return *arg1 - *arg2;
}

void assimilator(void* outputData, void* data) {
	int blockIndex, outputIndex, selectedBlockIndex, indexes[BLOCK_COUNT] = { 0 };

	for (outputIndex = 0; outputIndex < DATA_SIZE; ++outputIndex) {
		selectedBlockIndex = -1;
		for (blockIndex = 0; blockIndex < BLOCK_COUNT; ++blockIndex) {
			if (indexes[blockIndex] < BLOCK_SIZE && (selectedBlockIndex == -1 || ((int*)data)[blockIndex * BLOCK_SIZE + indexes[blockIndex]] < ((int*)data)[selectedBlockIndex * BLOCK_SIZE + indexes[selectedBlockIndex]])) {
				selectedBlockIndex = blockIndex;
			}
		}

		((int*)outputData)[outputIndex] = ((int*)data)[selectedBlockIndex * BLOCK_SIZE + indexes[selectedBlockIndex]];
		++indexes[selectedBlockIndex];
	}
}

void sort(void* outputData, void* inputData) {
	int blockIndex = 0;

	for (blockIndex = 0; blockIndex < BLOCK_COUNT; ++blockIndex) {
		qsort((int*)inputData + blockIndex * BLOCK_SIZE, BLOCK_SIZE, sizeof(int), compareFunction);
	}

	assimilator(outputData, inputData);
}

void printVector(void* data, int count/* 0 - full DATA_SIZE*/) {
	int index = 0;
	for (index = 0; (!count || index < count) && index < DATA_SIZE; index++) {
		printf("%d ", ((int*)data)[index]);
	}
	printf("\n");
}

int inputData[DATA_SIZE] = {
	1, 20, 29, 28, 10, 26, 25, 24,
	23, 22, 21, 30, 19, 18, 17, 16,
	15, 14, 13, 12, 11, 27, 9, 8,
	7, 6, 5, 4, 3, 2, 0, 31 };
int outputData[DATA_SIZE];

int main(void) {
	sort(outputData, inputData);
	printVector(outputData, 0);

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	//printf("Press Enter to continue . . .");
	//(void)getchar();
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)    
	system("pause");
#else
#endif
	return EXIT_SUCCESS;
}