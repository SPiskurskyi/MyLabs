#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 4 
#define ELEMENTS_COUNT 5 
#define PERMITTED_POSITIONS_COUNT ELEMENTS_COUNT 

#define PERMITTED_POSITION_FLAG 0x00000001
#define DEFINED_POSITION_FLAG 0x00000002

#define ELEMENT_INDEX_TO_ELEMENT_ID(INDEX) ((INDEX) + 1)
#define POSITION_INDEX_TO_POSITION_ID(INDEX) ((INDEX) + 1)

#define POSITIONS_DEFINITIONS {                                                                                       \
{{ PERMITTED_POSITION_FLAG }, { PERMITTED_POSITION_FLAG }, { 0 }, { 0 }}, \
{{ PERMITTED_POSITION_FLAG }, { 0 }, { PERMITTED_POSITION_FLAG }, { 0 }}, \
{{ 0 }, { 0 }, { 0 }, { PERMITTED_POSITION_FLAG }}, \
{{ 0 }, { 0 }, { 0 }, { 0 }}                        \
}

#define R_DEFINITIONS { \
{0, 5, 3, 0, 1}, \
{5, 0, 3, 3, 2}, \
{3, 3, 0, 1, 2}, \
{0, 3, 1, 0, 1}, \
{1, 2, 2, 1, 0}         \
}

typedef struct PositionStruct{
	unsigned int positionIndex;
	unsigned int positionIIndex;
	unsigned int positionJIndex;
	unsigned int elementIndex;
} Position;

typedef struct TablePositionStruct{
	unsigned int flags;
	unsigned int positionIndex;
	unsigned int elementIndex;
} TablePosition;

int compareForNormalSorting(const void * a, const void * b){
	long long int difference = (long long int)*(unsigned int*)a - (long long int)*(unsigned int*)b;
	difference < INT_MIN ? difference = INT_MIN : 0;
	difference > INT_MAX ? difference = INT_MAX : 0;
	return (int)difference;
}

int compareForReverseSorting(const void * a, const void * b){
	long long int difference = (long long int)*(unsigned int*)a - (long long int)*(unsigned int*)b;
	difference < INT_MIN ? difference = INT_MIN : 0;
	difference > INT_MAX ? difference = INT_MAX : 0;
	return (int)-difference;
}


int comparePositionsForNormalSorting(const void * a, const void * b){
	long long int difference = (long long int)((Position*)a)->positionIndex - (long long int)((Position*)b)->positionIndex;
	difference < INT_MIN ? difference = INT_MIN : 0;
	difference > INT_MAX ? difference = INT_MAX : 0;
	return (int)difference;
}

void printTablePositions(const char * const space, TablePosition(*tablePositions)[SIZE]){
	TablePosition currentTablePosition;
	for (unsigned int iIndex = 0; iIndex < SIZE; iIndex++){
		printf("%s|", space);
		for (unsigned int jIndex = 0; jIndex < SIZE; jIndex++){
			currentTablePosition = tablePositions[iIndex][jIndex];
			if (!(currentTablePosition.flags ^ (DEFINED_POSITION_FLAG | PERMITTED_POSITION_FLAG))){
				printf("| %d |", ELEMENT_INDEX_TO_ELEMENT_ID(currentTablePosition.elementIndex));
			}
			else if (currentTablePosition.flags & PERMITTED_POSITION_FLAG){
				printf("|   |");
			}
			else{
				printf("|---|");
			}
		}
		printf("|\n");
	}
}

void markFreePositions(TablePosition(*tablePositions)[SIZE], unsigned int firstJ){
	unsigned int positionIndex = 0;
	for (unsigned int iIndex = 0; iIndex < SIZE; ++iIndex){
		for (unsigned int jIndex = 0; jIndex < SIZE; ++jIndex){
			TablePosition  * currentTablePositionPointer = firstJ ? &tablePositions[jIndex][iIndex] : &tablePositions[iIndex][jIndex];
			if (currentTablePositionPointer->flags & PERMITTED_POSITION_FLAG){
				currentTablePositionPointer->positionIndex = positionIndex++;
			}
		}
	}
}

unsigned int getPositionsByFlags(Position * usedPositions, TablePosition(*tablePositions)[SIZE], unsigned int flagsFilter, unsigned int flags){
	unsigned int usedPositionsIndex = 0;
	TablePosition currentTablePosition;
	for (unsigned int iIndex = 0; iIndex < SIZE; ++iIndex){
		for (unsigned int jIndex = 0; jIndex < SIZE; ++jIndex){
			currentTablePosition = tablePositions[iIndex][jIndex];
			if (!(currentTablePosition.flags & flagsFilter ^ flags)){
				usedPositions[usedPositionsIndex].elementIndex = currentTablePosition.elementIndex;
				usedPositions[usedPositionsIndex].positionIndex = currentTablePosition.positionIndex;
				usedPositions[usedPositionsIndex].positionIIndex = iIndex;
				usedPositions[usedPositionsIndex].positionJIndex = jIndex;
				usedPositionsIndex++;
			}
		}
	}
	return usedPositionsIndex;
}

void genTableD(unsigned int(*tableD)[PERMITTED_POSITIONS_COUNT], TablePosition(*tablePositions)[SIZE]){
	TablePosition currentTablePositionForFirstPosition;
	TablePosition currentTablePositionForSecondPosition;
	for (unsigned int iIndexForFirstPosition = 0; iIndexForFirstPosition < SIZE; ++iIndexForFirstPosition){
		for (unsigned int jIndexForFirstPosition = 0; jIndexForFirstPosition < SIZE; ++jIndexForFirstPosition){
			currentTablePositionForFirstPosition = tablePositions[iIndexForFirstPosition][jIndexForFirstPosition];
			if (currentTablePositionForFirstPosition.flags & PERMITTED_POSITION_FLAG){
				for (unsigned int iIndexForSecondPosition = 0; iIndexForSecondPosition < SIZE; ++iIndexForSecondPosition){
					for (unsigned int jIndexForSecondPosition = 0; jIndexForSecondPosition < SIZE; ++jIndexForSecondPosition){
						currentTablePositionForSecondPosition = tablePositions[iIndexForSecondPosition][jIndexForSecondPosition];
						if (currentTablePositionForSecondPosition.flags & PERMITTED_POSITION_FLAG){
							unsigned int d = 0;
							iIndexForFirstPosition > iIndexForSecondPosition ? (d += iIndexForFirstPosition - iIndexForSecondPosition) : (d += iIndexForSecondPosition - iIndexForFirstPosition);
							jIndexForFirstPosition > jIndexForSecondPosition ? (d += jIndexForFirstPosition - jIndexForSecondPosition) : (d += jIndexForSecondPosition - jIndexForFirstPosition);
							tableD[currentTablePositionForFirstPosition.positionIndex % PERMITTED_POSITIONS_COUNT][currentTablePositionForSecondPosition.positionIndex % PERMITTED_POSITIONS_COUNT] = d;
							tableD[currentTablePositionForSecondPosition.positionIndex % PERMITTED_POSITIONS_COUNT][currentTablePositionForFirstPosition.positionIndex % PERMITTED_POSITIONS_COUNT] = d; // same
						}
					}
				}
			}
		}
	}
}

void printTableR(const char * const space, unsigned int(*tableR)[ELEMENTS_COUNT]){
	for (unsigned int iIndex = 0; iIndex < ELEMENTS_COUNT; iIndex++){
		printf("%s|", space);
		for (unsigned int jIndex = 0; jIndex < ELEMENTS_COUNT; jIndex++){
			printf("| %1d|", tableR[iIndex][jIndex]);
		}
		printf("|\n");
	}
}

void printTableD(const char * const space, unsigned int(*tableD)[PERMITTED_POSITIONS_COUNT]){
	for (unsigned int iIndex = 0; iIndex < PERMITTED_POSITIONS_COUNT; iIndex++){
		printf("%s|", space);
		for (unsigned int jIndex = 0; jIndex < PERMITTED_POSITIONS_COUNT; jIndex++){
			printf("| %1d|", tableD[iIndex][jIndex]);
		}
		printf("|\n");
	}
}

unsigned int computeF(unsigned int(*tableR)[ELEMENTS_COUNT], unsigned int(*tableD)[PERMITTED_POSITIONS_COUNT], TablePosition(*tablePositions)[SIZE], unsigned int firstFreeElementIndex){
	unsigned int sum = 0;

	Position usedPositions[SIZE * SIZE] = { 0 };
	unsigned int usedPositionsCount = 0;
	Position freePositions[SIZE * SIZE] = { 0 };
	unsigned int freePositionsCount = 0;

	unsigned int sortedRs[SIZE * SIZE] = { 0 };
	unsigned int sortedRsCount = 0;
	unsigned int sortedDs[SIZE * SIZE] = { 0 };
	unsigned int sortedDsCount = 0;

	usedPositionsCount = getPositionsByFlags(usedPositions, tablePositions, PERMITTED_POSITION_FLAG | DEFINED_POSITION_FLAG, PERMITTED_POSITION_FLAG | DEFINED_POSITION_FLAG);
	freePositionsCount = getPositionsByFlags(freePositions, tablePositions, PERMITTED_POSITION_FLAG | DEFINED_POSITION_FLAG, PERMITTED_POSITION_FLAG);

	// for used
	for (Position * beginUsedPositionPointer = usedPositions, *beyondUsedPositionPointer = usedPositions + usedPositionsCount; beginUsedPositionPointer < beyondUsedPositionPointer; beginUsedPositionPointer++){
		for (Position * usedPositionPointer = beginUsedPositionPointer + 1; usedPositionPointer < beyondUsedPositionPointer; usedPositionPointer++){
			sum +=
				tableR[beginUsedPositionPointer->elementIndex % PERMITTED_POSITIONS_COUNT][usedPositionPointer->elementIndex % PERMITTED_POSITIONS_COUNT]
				*
				tableD[beginUsedPositionPointer->positionIndex % PERMITTED_POSITIONS_COUNT][usedPositionPointer->positionIndex % PERMITTED_POSITIONS_COUNT];
		}
	}

	// for free
	for (unsigned int beginFreeElementIndex = firstFreeElementIndex; beginFreeElementIndex < ELEMENTS_COUNT; beginFreeElementIndex++){
		for (unsigned int freeElementIndex = beginFreeElementIndex + 1; freeElementIndex < ELEMENTS_COUNT; freeElementIndex++){
			sortedRs[sortedRsCount++] =
				tableR[beginFreeElementIndex][freeElementIndex];
		}
	}
	for (Position * beginFreePositionPointer = freePositions, *beyondFreePositionPointer = freePositions + freePositionsCount; beginFreePositionPointer < beyondFreePositionPointer; beginFreePositionPointer++){
		for (Position * freePositionPointer = beginFreePositionPointer + 1; freePositionPointer < beyondFreePositionPointer; freePositionPointer++){
			sortedDs[sortedDsCount++] =
				tableD[beginFreePositionPointer->positionIndex % PERMITTED_POSITIONS_COUNT]
				[freePositionPointer->positionIndex % PERMITTED_POSITIONS_COUNT];
		}
	}
	//if (sortedRsCount != sortedDsCount){
	//	printf("Bad table of positions\r\n");
	//	exit(-1);
	//}
	qsort(sortedRs, sortedRsCount, sizeof(unsigned int), compareForNormalSorting);
	qsort(sortedDs, sortedDsCount, sizeof(unsigned int), compareForReverseSorting);
	for (unsigned int index = 0; index < sortedRsCount; ++index){
		sum += sortedRs[index] * sortedDs[index];
	}

	// for used<->free
	for (Position * usedPositionPointer = usedPositions, *beyondUsedPositionPointer = usedPositions + usedPositionsCount; usedPositionPointer < beyondUsedPositionPointer; usedPositionPointer++){
		sortedRsCount = 0;
		sortedDsCount = 0;
		for (unsigned int freeElementIndex = firstFreeElementIndex; freeElementIndex < ELEMENTS_COUNT; freeElementIndex++){
			sortedRs[sortedRsCount++] =
				tableR[usedPositionPointer->elementIndex % PERMITTED_POSITIONS_COUNT][freeElementIndex];
		}
		for (Position * freePositionPointer = freePositions, *beyondFreePositionPointer = freePositions + freePositionsCount; freePositionPointer < beyondFreePositionPointer; freePositionPointer++){
			sortedDs[sortedDsCount++] =
				tableD[usedPositionPointer->positionIndex % PERMITTED_POSITIONS_COUNT]
				[freePositionPointer->positionIndex % PERMITTED_POSITIONS_COUNT];
		}
		if (sortedRsCount != sortedDsCount){ // REMOVE!
			printf("Bad table of positions\r\n");
			exit(-1);
		}
		qsort(sortedRs, sortedRsCount, sizeof(unsigned int), compareForNormalSorting);
		qsort(sortedDs, sortedDsCount, sizeof(unsigned int), compareForReverseSorting);
		for (unsigned int index = 0; index < sortedRsCount; ++index){
			sum += sortedRs[index] * sortedDs[index];
		}
	}

	return sum;
}

void tablePositionsProcessing(unsigned int(*tableR)[ELEMENTS_COUNT], unsigned int(*tableD)[PERMITTED_POSITIONS_COUNT], TablePosition(*tablePositions)[SIZE]){
	Position freePositions[SIZE * SIZE] = { 0 };
	unsigned int freePositionsCount = getPositionsByFlags(freePositions, tablePositions, PERMITTED_POSITION_FLAG | DEFINED_POSITION_FLAG, PERMITTED_POSITION_FLAG);
	qsort(freePositions, freePositionsCount, sizeof(Position), comparePositionsForNormalSorting);

	if (freePositionsCount != PERMITTED_POSITIONS_COUNT) {
		printf("Bad table of positions\r\n");
		exit(-1);
	}

	unsigned int minF = computeF(tableR, tableD, tablePositions, 0);
	printf("Fmin = %d\n\n", minF);
	for (unsigned int elementIndex = 0; elementIndex < ELEMENTS_COUNT; elementIndex++){
		printf("%d:\n", ELEMENT_INDEX_TO_ELEMENT_ID(elementIndex));
		unsigned int currentMinF = INT_MAX;
		unsigned int verifiedPositionForElementIIndex = 0;
		unsigned int verifiedPositionForElementJIndex = 0;
		unsigned int etap = 0;
		for (Position * freePositionPointer = freePositions, *beyondFreePositionPointer = freePositions + freePositionsCount; freePositionPointer < beyondFreePositionPointer; freePositionPointer++){
			unsigned int positionForElementIIndex = freePositionPointer->positionIIndex % SIZE;
			unsigned int positionForElementJIndex = freePositionPointer->positionJIndex % SIZE;
			if (!(tablePositions[positionForElementIIndex][positionForElementJIndex].flags & (PERMITTED_POSITION_FLAG | DEFINED_POSITION_FLAG) ^ PERMITTED_POSITION_FLAG)){
				tablePositions[positionForElementIIndex][positionForElementJIndex].flags |= DEFINED_POSITION_FLAG;
				tablePositions[positionForElementIIndex][positionForElementJIndex].elementIndex = elementIndex;
				unsigned int currentF = computeF(tableR, tableD, tablePositions, elementIndex + 1);
				printf("     %d.%d. Set element X%d in position %d:\r\n", ELEMENT_INDEX_TO_ELEMENT_ID(elementIndex), ++etap, ELEMENT_INDEX_TO_ELEMENT_ID(elementIndex), POSITION_INDEX_TO_POSITION_ID(freePositionPointer->positionIndex));
				printTablePositions("     ", tablePositions);
				printf("     F = %d\n\n", currentF);
				tablePositions[positionForElementIIndex][positionForElementJIndex].flags &= ~DEFINED_POSITION_FLAG;
				currentMinF > currentF ? (
					currentMinF = currentF,
					verifiedPositionForElementIIndex = positionForElementIIndex,
					verifiedPositionForElementJIndex = positionForElementJIndex
					) : 0;
				if (minF == currentF) { // <=
					break;
				}
			}
		}
		tablePositions[verifiedPositionForElementIIndex][verifiedPositionForElementJIndex].flags |= DEFINED_POSITION_FLAG;
		tablePositions[verifiedPositionForElementIIndex][verifiedPositionForElementJIndex].elementIndex = elementIndex;
		printf("   ->%d.%d. Fix element X%d in position %d:\r\n", ELEMENT_INDEX_TO_ELEMENT_ID(elementIndex), ++etap, ELEMENT_INDEX_TO_ELEMENT_ID(verifiedPositionForElementIIndex), POSITION_INDEX_TO_POSITION_ID(verifiedPositionForElementJIndex));
		printTablePositions("     ", tablePositions);
		minF = currentMinF;
		printf("     Fmin = F = %d\r\n", minF);
		printf("\n");

	}
}

int main(void){
	unsigned int tableR[ELEMENTS_COUNT][ELEMENTS_COUNT] = R_DEFINITIONS;
	unsigned int tableD[PERMITTED_POSITIONS_COUNT][PERMITTED_POSITIONS_COUNT];
	TablePosition tablePositions[SIZE][SIZE] = POSITIONS_DEFINITIONS;

	markFreePositions(tablePositions, 1);
	genTableD(tableD, tablePositions);

	printf("Positions:\n");
	printTablePositions("", tablePositions);
	printf("\n");
	printf("R:\n");
	printTableR("", tableR);
	printf("\n");
	printf("D:\n");
	printTableD("", tableD);
	printf("\n");

	tablePositionsProcessing(tableR, tableD, tablePositions);

	printf("Processed positions:\n\n");
	printTablePositions("", tablePositions);
	printf("F = %d:\n", computeF(tableR, tableD, tablePositions, ELEMENTS_COUNT));

	printf("\n\nPress Enter to continue . . .");
	(void)getchar();

	return 0;
}
