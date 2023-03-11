#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int size, i;
	const int N = 5;
	int Arr[N];
	FILE* pf;
	char Buf[128] = ""; char* pch;
	/*------- file reading -------*/
	size = 0;
	pf = fopen("MyFile.txt", "rt");
	if (pf != 0)
	{
		pch = fgets(Buf, sizeof(Buf), pf);
		while (pch != 0 && size < N)
		{
			Arr[size] = atoi(Buf);
			size++;
			pch = fgets(Buf, sizeof(Buf), pf);
		}
		fclose(pf);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Arr[i] == Arr[i + j])
				Arr[i + j] = 0;
		}

	}
	pf = fopen("MyFile.txt", "at");
	for (int i = 0; i < N; i++)
		fprintf(pf, "\nArr[%d] = %d\n", i, Arr[i]);
	fclose(pf);
	return 0;
}