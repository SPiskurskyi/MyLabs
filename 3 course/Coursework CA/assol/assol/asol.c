/* Assembler for LC */
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXLINELENGTH 1000
#define MAXNUMLABELS 67108864
#define MAXLABELLENGTH 18 /* includes the null character termination */

#define START_OPCODE 24
#define START_REG_A 8
#define START_REG_B 16

#define ADD 0
#define NAND 1
#define LW 2
#define SW 3
#define BEQ 4
#define JALR 5
#define HALT 6
#define MUL 7
//арефметичні операції
#define DEC 8
#define XDIV 9
#define XIMUL 10
//логічні операції
#define SHL 11
  /*
 * Read and parse a line of the assembly-language file.  Fields are returned
 * in label, opcode, arg0, arg1, arg2 (these strings must have memory already
 * allocated to them).
 *
 * Return values:
 *     0 if reached end of file
 *     1 if all went well
 *
 * exit(1) if line is too long.
 */
int readAndParse(FILE* inFilePtr, char* label, char* opcode, char* arg0, char* arg1, char* arg2)
{
	char line[MAXLINELENGTH];
	char* ptr = line;

	/* delete prior values */
	label[0] = opcode[0] = arg0[0] = arg1[0] = arg2[0] = '\0';

	/* read the line from the assembly-language file */
	if (fgets(line, MAXLINELENGTH, inFilePtr) == NULL) {
		/* reached end of file */
		return(0);
	}

	/* check for line too long */
	if (strlen(line) == MAXLINELENGTH - 1) {
		printf("error: line too long\n");
		exit(1);
	}

	/* is there a label? */
	ptr = line;
	if (sscanf(ptr, "%[^\t\n ]", label)) {
		/* successfully read label; advance pointer over the label */
		ptr += strlen(label);
	}

	/*
	 * Parse the rest of the line.  Would be nice to have real regular
	 * expressions, but scanf will suffice.
	 */
	sscanf(ptr, "%*[\t\n\r ]%[^\t\n\r ]%*[\t\n\r ]%[^\t\n\r ]%*[\t\n\r ]%[^\t\n\r ]%*[\t\n\r ]%[^\t\n\r ]",
		opcode, arg0, arg1, arg2);
	return(1);
}

int translateSymbol(char labelArray[MAXNUMLABELS][MAXLABELLENGTH], int labelAddress[MAXNUMLABELS], int numLabels, char* symbol)
{
	int i;

	/* search through address label table */
	for (i = 0; i < numLabels && strcmp(symbol, labelArray[i]); i++) {
	}

	if (i >= numLabels) {
		printf("error: missing label %s\n", symbol);
		exit(1);
	}

	return(labelAddress[i]);
}

int isNumber(char* string)
{
	/* return 1 if string is a number */
	int i;
	return((sscanf(string, "%d", &i)) == 1);
}

/*
 * Test register argument; make sure it's in range and has no bad characters.
 */
void testRegArg(char* arg)
{
	int num;
	char c;

	if (atoi(arg) < 0 || atoi(arg) > 255) {
		printf("error: register out of range\n");
		exit(2);
	}
	if (sscanf(arg, "%d%c", &num, &c) != 1) {
		printf("bad character in register argument\n");
		exit(2);
	}
}

/*
 * Test addressField argument.
 */
void testAddrArg(char* arg)
{
	int num;
	char c;

	/* test numeric addressField */
	if (isNumber(arg)) {
		if (sscanf(arg, "%d%c", &num, &c) != 1) {
			printf("bad character in addressField\n");
			exit(2);
		}
	}
}

