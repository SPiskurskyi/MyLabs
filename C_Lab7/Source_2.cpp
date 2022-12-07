#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE* pf;
	int size, i;
	int Arr[10];
	size = 10;
	for (i = 0; i < size; i++)
	{
		printf("Enter Arr[%d]:", i);
		scanf("%d", &Arr[i]);
	}
	pf = fopen("MyFileIn.bin", "wb");
	if (pf != 0)
	{
		fwrite(Arr, sizeof(int), size, pf);
		fclose(pf);
	}
	pf = fopen("MyFileIn.bin", "rb");
	if (pf != 0)
	{
		fread(Arr, sizeof(int), size, pf);
		fclose(pf);
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (Arr[i] == Arr[i + j])
				Arr[i + j] = 0;
		}

	}
	pf = fopen("MyFileOut.bin", "wb");
	if (pf != 0)
	{
		for (int i = 0; i < size; i++)
			fwrite(&Arr[i], sizeof(int), size, pf);
		fclose(pf);
	}
	pf = fopen("MyFileOut.bin", "rb");
	if (pf != 0)
	{
		fread(&Arr, sizeof(int), 10, pf);
		fclose(pf);
	}
	for (int i = 0; i < 10; i++)
		printf("\nArr[%d] = %d\n", i, Arr[i]);
	return 0;
}