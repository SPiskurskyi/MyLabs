/* Assembler for LC */
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#define MAXLINELENGTH 1000 
#define MAXNUMLABELS 256 
#define MAXLABELLENGTH 7 /* includes the null character termination */ 

#define ADD 0 
#define NAND 1 
#define LW 2 
#define SW 3 
#define BEQ 4 
#define JALR 5 
#define HALT 6 
#define NOOP 7 

#define DIV 8 
#define XIDIV 9 
#define XADD 10 

#define AND 11 
#define XOR 12 
#define CMPL 13 

#define JMAE 14 
#define JMLE 15 

#define SBB 16 
#define BT 17 
#define RCR 18 

#define LWB 19 
#define DIVB 20 
#define XORB 21 
#define ANDB 22 

int readAndParse(FILE*, char*, char*, char*, char*, char*);
int translateSymbol(char labelArray[MAXNUMLABELS][MAXLABELLENGTH], int labelAddress[MAXNUMLABELS], int, char*);
int isNumber(char*); void testRegArg(char*);
void testAddrArg(char*);

int main(int argc, char* argv[])
{
    char* inFileString, * outFileString;  	FILE* inFilePtr, * outFilePtr;
    int address;
    char label[MAXLINELENGTH], opcode[MAXLINELENGTH], arg0[MAXLINELENGTH], arg1[MAXLINELENGTH], arg2[MAXLINELENGTH], argTmp[MAXLINELENGTH];  	int i;
    int numLabels = 0;
    int num;
    int addressField;

    char labelArray[MAXNUMLABELS][MAXLABELLENGTH];  	int labelAddress[MAXNUMLABELS];

    if (argc != 3)
    {
        printf("error: usage: %s <assembly-code-file> <machine-code-file>\n",
            argv[0]);
        exit(1);
    }
    inFileString = argv[1]; outFileString = argv[2];
    inFilePtr = fopen(inFileString, "r"); if (inFilePtr == NULL)
    {
        printf("error in opening %s\n", inFileString);
        exit(1);
    }
    outFilePtr = fopen(outFileString, "w");  	if (outFilePtr == NULL)
    {
        printf("error in opening %s\n", outFileString);
        exit(1);
    }

    /* map symbols to addresses */

    /* assume address start at 0 */
    for (address = 0; readAndParse(inFilePtr, label, opcode, arg0, arg1, arg2);
        address++)
    {
        /*
        printf("%d: label=%s, opcode=%s, arg0=%s, arg1=%s, arg2=%s\n",
            address, label, opcode, arg0, arg1, arg2);
        */

        /* check for illegal opcode */  	 	if (strcmp(opcode, "add") && strcmp(opcode, "nand") && strcmp(opcode, "lw") && strcmp(opcode, "sw") && strcmp(opcode, "beq") && strcmp(opcode, "jalr") && strcmp(opcode, "halt") && strcmp(opcode, "noop") && strcmp(opcode, ".fill") && strcmp(opcode, "div") && strcmp(opcode, "xidiv") && strcmp(opcode, "xadd") && strcmp(opcode, "xor") && strcmp(opcode, "and") && strcmp(opcode, "cmpl") && strcmp(opcode, "jmae") && strcmp(opcode, "jmle") && strcmp(opcode, "sbb") && strcmp(opcode, "bt") && strcmp(opcode, "rcr") && strcmp(opcode, "lwb") && strcmp(opcode, "divb") && strcmp(opcode, "xorb") && strcmp(opcode, "andb"))
        {
            printf("error: unrecognized opcode %s at address %d\n", opcode, address);
            exit(1);
        }

        /* check register fields */
        if (!strcmp(opcode, "add") || !strcmp(opcode, "nand") || !strcmp(opcode, "lw") || !strcmp(opcode, "sw") ||
            !strcmp(opcode, "beq") || !strcmp(opcode, "jalr") ||
            !strcmp(opcode, "div") || !strcmp(opcode, "bt") ||
            !strcmp(opcode, "xidiv") || !strcmp(opcode, "xadd") ||
            !strcmp(opcode, "xor") || !strcmp(opcode, "and") ||
            !strcmp(opcode, "cmpl") || !strcmp(opcode, "jmae") ||
            !strcmp(opcode, "jmle") || !strcmp(opcode, "sbb") ||
            !strcmp(opcode, "rcr") || !strcmp(opcode, "xorb") ||
            !strcmp(opcode, "andb") || !strcmp(opcode, "divb"))
        {
            testRegArg(arg0); testRegArg(arg1);
        }
        if (!strcmp(opcode, "lwb"))
        {
            testRegArg(arg0);
        }  	if (!strcmp(opcode, "add") || !strcmp(opcode, "nand") ||
            !strcmp(opcode, "div") || !strcmp(opcode, "sbb") ||
            !strcmp(opcode, "xidiv") || !strcmp(opcode, "xadd") ||
            !strcmp(opcode, "xor") || !strcmp(opcode, "and") ||
            !strcmp(opcode, "cmpl") || !strcmp(opcode, "rcr"))
        {
            testRegArg(arg2);
        }

        /* check addressField */
        if (!strcmp(opcode, "lw") || !strcmp(opcode, "sw") ||
            !strcmp(opcode, "beq") || !strcmp(opcode, "jmae") ||
            !strcmp(opcode, "jmle"))
        {
            testAddrArg(arg2);
        }
        if (!strcmp(opcode, ".fill"))
        {
            testAddrArg(arg0);
        }

        /* check for enough arguments */
        if ((strcmp(opcode, "halt") && strcmp(opcode, "noop") && strcmp(opcode, ".fill") && strcmp(opcode, "jalr") &&
            arg2[0] == '\0') || (!strcmp(opcode, "jalr") && arg1[0] == '\0') ||
            (!strcmp(opcode, ".fill") && arg0[0] == '\0'))
        {
            printf("error at address %d: not enough arguments\n", address);
            exit(2);
        }

        if (label[0] != '\0')
        {
            /* check for labels that are too long */
            if (strlen(label) >= MAXLABELLENGTH)
            {
                printf("label too long\n");  	 	 	 	exit(2);
            }

            /* make sure label starts with letter */
            if (!sscanf(label, "%[a-zA-Z]", argTmp))
            {
                printf("label doesn't start with letter\n");
                exit(2);
            }

            /* make sure label consists of only letters and numbers */  	 	 	sscanf(label, "%[a-zA-Z0-9]", argTmp);
            if (strcmp(argTmp, label))
            {
                printf("label has character other than letters and numbers\n");
                exit(2);
            }
            /* look for duplicate label */  	for (i = 0; i < numLabels; i++)
            {
                if (!strcmp(label, labelArray[i]))
                {
                    printf("error: duplicate label %s at address %d\n",
                        label, address);  	 	 	exit(1);
                }
            }
            /* see if there are too many labels */
            if (numLabels >= MAXNUMLABELS)
            {
                printf("error: too many labels (label=%s)\n", label);
                exit(2);
            }

            strcpy(labelArray[numLabels], label);
            labelAddress[numLabels++] = address;
        }
    }

    for (i = 0; i < numLabels; i++)
    {
        /* printf("%s = %d\n", labelArray[i], labelAddress[i]); */
    }

    /* now do second pass (print machine code, with symbols filled in as  addresses) */
    rewind(inFilePtr);
    for (address = 0; readAndParse(inFilePtr, label, opcode, arg0, arg1, arg2);
        address++)
    {
        if (!strcmp(opcode, "add"))
        {
            num = (ADD << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | atoi(arg2);
        }
        else if (!strcmp(opcode, "nand"))
        {
            num = (NAND << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | atoi(arg2);
        }
        else if (!strcmp(opcode, "jalr"))
        {
            num = (JALR << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | atoi(arg2);
        }
        else if (!strcmp(opcode, "halt"))
        {
            num = (HALT << 8);
        }
        else if (!strcmp(opcode, "noop"))
        {
            num = (NOOP << 8);
        }
        else if (!strcmp(opcode, "lw") || !strcmp(opcode, "sw") ||
            !strcmp(opcode, "beq") || !strcmp(opcode, "jmae") ||
            !strcmp(opcode, "jmle"))
        {
            /* if arg2 is symbolic, then translate into an address */
            if (!isNumber(arg2))
            {
                addressField = translateSymbol(labelArray, labelAddress, numLabels, arg2);
                /*
                printf("%s being translated into %d\n", arg2, addressField);
                */
                if (!strcmp(opcode, "beq") || !strcmp(opcode, "jmle") || !strcmp(opcode, "jmae"))
                {
                    addressField = addressField - address - 1;
                }
            }
            else
            {
                addressField = atoi(arg2);
            }
            if (addressField < -32768 || addressField > 32767)
            {
                printf("error: offset %d out of range\n", addressField);
                exit(1);
            }

            /* truncate the offset field, in case it's negative */
            addressField = addressField & 0xF;

            if (!strcmp(opcode, "beq"))
            {
                num = (BEQ << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | addressField;
            }
            else if (!strcmp(opcode, "jmae"))
            {
                num = (JMAE << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | addressField;
            }
            else if (!strcmp(opcode, "jmle"))
            {
                num = (JMLE << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | addressField;
            }
            else if (!strcmp(opcode, "lw"))
            {
                num = (LW << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | addressField;
            }
            else
            {
                num = (SW << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | addressField;
            }
        }
        else if (!strcmp(opcode, ".fill"))
        {
            if (!isNumber(arg0))
            {
                num = translateSymbol(labelArray, labelAddress, numLabels, arg0);
            }
            else
            {
                num = atoi(arg0);
            }
        }
        else if (!strcmp(opcode, "div"))
        {
            num = (DIV << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | atoi(arg2);
        }
        else if (!strcmp(opcode, "xidiv"))
        {
            num = (XIDIV << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | atoi(arg2);
        }
        else if (!strcmp(opcode, "xadd"))
        {
            num = (XADD << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | atoi(arg2);
        }
        else if (!strcmp(opcode, "xor"))
        {
            num = (XOR << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | atoi(arg2);
        }
        else if (!strcmp(opcode, "and"))
        {
            num = (AND << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | atoi(arg2);
        }
        else if (!strcmp(opcode, "cmpl"))
        {
            num = (CMPL << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | atoi(arg2);
        }
        else if (!strcmp(opcode, "bt"))
        {
            num = (BT << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4);
        }
        else if (!strcmp(opcode, "sbb"))
        {
            num = (SBB << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | atoi(arg2);
        }
        else if (!strcmp(opcode, "rcr"))
        {
            num = (RCR << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4) | atoi(arg2);
        }
        else if (!strcmp(opcode, "lwb"))
        {
            num = (LWB << 8) | (atoi(arg0) << 6);
        }
        else if (!strcmp(opcode, "divb"))
        {
            num = (DIVB << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4);
        }
        else if (!strcmp(opcode, "xorb"))
        {
            num = (XORB << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4);
        }
        else if (!strcmp(opcode, "andb"))
        {
            num = (ANDB << 8) | (atoi(arg0) << 6) | (atoi(arg1) << 4);
        }
        /* printf("(address %d): %d (hex 0x%x)\n", address, num, num); */
        fprintf(outFilePtr, "%d\n", num);
    }

    exit(0);
}

/*
*	Read and parse a line of the assembly-language file.  Fields are returned  * in label, opcode, arg0, arg1, arg2 (these strings must have memory already  * allocated to them).  *
*	Return values:
*	0 if reached end of file
*	1 if all went well
 *
*	exit(1) if line is too long.
 */
int readAndParse(FILE* inFilePtr, char* label, char* opcode, char* arg0,
    char* arg1, char* arg2)
{
    char line[MAXLINELENGTH];
    char* ptr = line;
    /* delete prior values */ label[0] = opcode[0] = arg0[0] = arg1[0] = arg2[0] = '\0';
    /* read the line from the assembly-language file */
    if (fgets(line, MAXLINELENGTH, inFilePtr) == NULL)
    {
        /* reached end of file */  return (0);
    }
    /* check for line too long */
    if (strlen(line) == MAXLINELENGTH - 1)
    {
        printf("error: line too long\n");
        exit(1);
    }

    /* is there a label? */
    ptr = line;
    if (sscanf(ptr, "%[^\t\n ]", label))
    {
        /* successfully read label; advance pointer over the label */  	 	ptr += strlen(label);
    }

    /*
     * Parse the rest of the line.  Would be nice to have real regular  	 * expressions, but scanf will suffice.
     */
    sscanf(ptr, "%*[\t\n\r ]%[^\t\n\r ]%*[\t\n\r ]%[^\t\n\r ]%*[\t\n\r ]%[^\t\n\r ]%*[\t\n\r ]%[^\t\n\r ]", opcode, arg0, arg1, arg2);  	return (1);
}

int translateSymbol(char labelArray[MAXNUMLABELS][MAXLABELLENGTH],
    int labelAddress[MAXNUMLABELS], int numLabels, char* symbol)
{
    int i;

    /* search through address label table */
    for (i = 0; i < numLabels && strcmp(symbol, labelArray[i]); i++)
    {
    }

    if (i >= numLabels)
    {
        printf("error: missing label %s\n", symbol);  	 	exit(1);
    }

    return (labelAddress[i]);
}

int isNumber(char* string)
{
    /* return 1 if string is a number */
    int i;
    return ((sscanf(string, "%d", &i)) == 1);
}

/*
 * Test register argument; make sure it's in range and has no bad characters.
 */
void testRegArg(char* arg)
{
    int num; char c;
    if (atoi(arg) < 0 || atoi(arg) > 7)
    {
        printf("error: register out of range\n");
        exit(2);
    }
    if (sscanf(arg, "%d%c", &num, &c) != 1)
    {
        printf("bad character in register argument\n");
        exit(2);
    }
}

/*
 * Test addressField argument.
 */
void testAddrArg(char* arg)
{
    int num;  	char c;

    /* test numeric addressField */  if (isNumber(arg))
    {
        if (sscanf(arg, "%d%c", &num, &c) != 1)
        {
            printf("bad character in addressField\n");
            exit(2);
        }
    }
}
