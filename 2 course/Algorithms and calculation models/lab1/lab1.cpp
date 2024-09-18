#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 32

#define REPEAT_COUNT 1000000
#define REPEATOR(count, code) \
for (unsigned int indexIteration = (count); indexIteration--;){ code; }
double getCurrentTime() {
	clock_t time = clock();
	if (time != (clock_t)-1) {
		return ((double)time / (double)CLOCKS_PER_SEC);
	}
	return 0.; // else
}
void printVector(void* data, int count) {
	int index = 0;
	for (index = 0; (!count || index < count) && index < SIZE; index++) {
		printf("%d ", ((int*)data)[index]);
	}
	printf("\n");
}

void bulbSort(int* arr, int start, int end)
{
	int index, temp;
	++end;
	while (start < --end)
	{
		for (index = start; index < end; ++index)
		{
			if (arr[index] > arr[index + 1])
			{
				temp = arr[index];
				arr[index] = arr[index + 1];
				arr[index + 1] = temp;
			}
		}
	}
}
void insertSort(int* arr, int start, int end)
{
	int j, temp;
	for (int i = 1; i < end; i++)
	{
		temp = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

int main(void)
{
	int data[SIZE] = { 1, 20, 29, 28, 10, 26, 25, 24,
		23, 22, 21, 30, 19, 18, 17, 16,
		15, 14, 13, 12, 11, 27, 9, 8,
		7, 6, 5, 4, 3, 2, 0, 31 };
	double startTime, endTime;

	//bubl sort
	startTime = getCurrentTime();
	REPEATOR(REPEAT_COUNT, bulbSort(data, 0, SIZE - 1));
	endTime = getCurrentTime();
	printf("bublSort \t run time: %dns\r\n", (unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));
	printVector(data, 0);

	int data1[SIZE] = { 1, 20, 29, 28, 10, 26, 25, 24,
		23, 22, 21, 30, 19, 18, 17, 16,
		15, 14, 13, 12, 11, 27, 9, 8,
		7, 6, 5, 4, 3, 2, 0, 31 };

	//insert sort
	startTime = getCurrentTime();
	REPEATOR(REPEAT_COUNT, insertSort(data1, 0, SIZE - 1));
	endTime = getCurrentTime();
	printf("insertSort \t run time: %dns\r\n", (unsigned int)((endTime - startTime) * (double)(1000000000 / REPEAT_COUNT)));
	printVector(data1, 0);

	(void)getchar();
	return EXIT_SUCCESS;
}
