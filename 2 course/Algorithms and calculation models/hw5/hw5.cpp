#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h>

#define NANOSECONDS_PER_SECOND_NUMBER 1000000000

#define DATA_TYPE_ float
#define DATA_TYPE  volatile DATA_TYPE_

#define A  4
#define B  5
#define C  5
#define D  4
#define E  5
#define F  5
#define G  7
#define H  6

#define REPEAT_COUNT 1000000
#define REPEATOR(count, code) \
for (unsigned int indexIteration = (count); indexIteration--;){ code; }

float getCurrentTime() {
	clock_t time = clock();
	if (time != (clock_t)-1) {
		return ((float)time / (float)CLOCKS_PER_SEC);
	}
	return 0.; 
}

void run_native(DATA_TYPE* const dArr) {
	DATA_TYPE* const dAC = dArr;
	DATA_TYPE* const dA = &dAC[0];
	DATA_TYPE* const dC = &dAC[1];
	DATA_TYPE* const dB = &dAC[2];
	DATA_TYPE* const dD = &dAC[3];
	DATA_TYPE* const dE = &dAC[4];
	DATA_TYPE* const dF = &dAC[5];
	DATA_TYPE* const dG = &dAC[6];
	DATA_TYPE* const dH = &dAC[7];
	DATA_TYPE* const dResult = &dAC[8];
	DATA_TYPE* const dX1 = &dResult[0];

	*dX1 = -((*dA - *dB) / (*dC - *dD) + (*dE - *dF) / (*dG - *dH));
}

void run_search(DATA_TYPE* const dArr)
{
	DATA_TYPE* const dAC = dArr;
	DATA_TYPE* const dA = &dAC[0];
	DATA_TYPE* const dC = &dAC[1];
	DATA_TYPE* const dB = &dAC[2];
	DATA_TYPE* const dD = &dAC[3];
	DATA_TYPE* const dE = &dAC[4];
	DATA_TYPE* const dF = &dAC[5];
	DATA_TYPE* const dG = &dAC[6];
	DATA_TYPE* const dH = &dAC[7];
	DATA_TYPE* const dResult = &dAC[8];
	DATA_TYPE* const dX1 = &dResult[0];

	*dX1 = 0.; // reset the result

	unsigned int* const uX1 = (unsigned int* const)dX1;
	for (*uX1 = 0; *uX1 < ~0; ++ * uX1) {
		if (*dX1 + (*dA - *dB) / (*dC - *dD) + (*dE - *dF) / (*dG - *dH) == 0) {
			break;
		}
	}
}


void printResult(char* const title, DATA_TYPE* const dArr, unsigned int runTime, unsigned int runTimeBySeconds)
{
	DATA_TYPE* const dAC = dArr;
	DATA_TYPE* const dA = &dAC[0];
	DATA_TYPE* const dC = &dAC[1];
	DATA_TYPE* const dB = &dAC[2];
	DATA_TYPE* const dD = &dAC[3];
	DATA_TYPE* const dE = &dAC[4];
	DATA_TYPE* const dF = &dAC[5];
	DATA_TYPE* const dG = &dAC[6];
	DATA_TYPE* const dH = &dAC[7];
	DATA_TYPE* const dResult = &dAC[8];
	DATA_TYPE* const dX1 = &dResult[0];

	printf("%s:\r\n", title);
	printf("X + (%f - %f) / (%f - %f) + (%f - %f) / (%f - %f) = 0;\r\n", *dA, *dB, *dC, *dD, *dE, *dF, *dG, *dH);
	printf("x1 = %5.2f;\r\n", *dX1);
	if (runTime)
		printf("run time: %dns\r\n\r\n", runTime);
	else if (runTimeBySeconds)
		printf("run time: %ds (~%d.000.000.000ns)\r\n\r\n", runTimeBySeconds, runTimeBySeconds);
}

int main()
{
	DATA_TYPE* const dArr = (DATA_TYPE_*)malloc(18 * sizeof(DATA_TYPE_));

	if (!dArr) {
		return 0;
	}

	DATA_TYPE* const dAC = dArr;
	DATA_TYPE* const dA = &dAC[0];
	DATA_TYPE* const dC = &dAC[1];
	DATA_TYPE* const dB = &dAC[2];
	DATA_TYPE* const dD = &dAC[3];
	DATA_TYPE* const dE = &dAC[4];
	DATA_TYPE* const dF = &dAC[5];
	DATA_TYPE* const dG = &dAC[6];
	DATA_TYPE* const dH = &dAC[7];
	DATA_TYPE* const dResult = &dAC[8];
	DATA_TYPE* const dX1 = &dResult[0];

	*dA = (DATA_TYPE_)A;
	*dB = (DATA_TYPE_)B;
	*dC = (DATA_TYPE_)C;
	*dD = (DATA_TYPE_)D;
	*dE = (DATA_TYPE_)E;
	*dF = (DATA_TYPE_)F;
	*dG = (DATA_TYPE_)G;
	*dH = (DATA_TYPE_)H;

	float startTime, endTime;

	
	startTime = getCurrentTime();
	REPEATOR(REPEAT_COUNT, run_native(dArr););
	endTime = getCurrentTime();
	printResult((char*)"compute by the formula with compiler optimization",
		dArr,
		(unsigned int)((endTime - startTime) * (NANOSECONDS_PER_SECOND_NUMBER / REPEAT_COUNT)), 0);

	printf("please wait, the full search takes a few tens of seconds...");
	startTime = getCurrentTime();
	run_search(dArr);
	endTime = getCurrentTime();
	printf("\r                                                           \r");
	printResult((char*)"search",
		dArr,
		0, (unsigned int)(endTime - startTime));

	printf("Press Enter to continue . . .");
	(void)getchar();
	return 0;
}