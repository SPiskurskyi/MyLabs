/*
 * Instruction-level simulator for the LC
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define NUMMEMORY 256 /* maximum number of words in memory */ 
#define NUMREGS 8 	  /* number of machine registers */ 
#define MAXLINELENGTH 1000 

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

typedef struct stateStruct
{
    int pc;  	int mem[NUMMEMORY];  	int reg[NUMREGS];  	int numMemory;  	int CF;
    int base;
} stateType;

void printState(stateType*); void run(stateType);
int convertNum(int);

int main(int argc, char* argv[])
{
    int i;  	char line[MAXLINELENGTH];  	stateType state;  	FILE* filePtr;
    state.CF = 0;
    if (argc != 2)
    {
        printf("error: usage: %s <machine-code file>\n", argv[0]);
        exit(1);
    }
    /* initialize memories and registers */
    for (i = 0; i < NUMMEMORY; i++)
    {
        state.mem[i] = 0;
    }
    for (i = 0; i < NUMREGS; i++)
    {
        state.reg[i] = 0;
    }

    state.pc = 0;

    /* read machine-code file into instruction/data memory (starting at  	address 0) */

    filePtr = fopen(argv[1], "r");
    if (filePtr == NULL)
    {
        printf("error: can't open file %s\n", argv[1]);
        perror("fopen");  	 	exit(1);
    }

    for (state.numMemory = 0; fgets(line, MAXLINELENGTH, filePtr) != NULL;
        state.numMemory++)
    {
        if (state.numMemory >= NUMMEMORY)
        {
            printf("exceeded memory size\n");
            exit(1);
        }
        if (sscanf(line, "%d", state.mem + state.numMemory) != 1)
        {
            printf("error in reading address %d\n", state.numMemory);
            exit(1);
        }
        printf("memory[%d]=%d\n", state.numMemory, state.mem[state.numMemory]);
    }

    printf("\n");

    /* run never returns */  	run(state);

    return (0);
}

void run(stateType state)
{
    int arg0, arg1, arg2, addressField; int instructions = 0; int opcode;
    int maxMem = -1; /* highest memory address touched during run */ state.CF = 0; state.base = 0;
    for (; 1; instructions++)
    { /* infinite loop, exits when it executes halt */
        printState(&state);
        if (state.pc < 0 || state.pc >= NUMMEMORY)
        {
            printf("pc went out of the memory range\n");
            exit(1);
        }
        maxMem = (state.pc > maxMem) ? state.pc : maxMem;

        /* this is to make the following code easier to read */
        opcode = state.mem[state.pc] >> 8;  	 	arg0 = (state.mem[state.pc] >> 6) & 0x3;  	 	arg1 = (state.mem[state.pc] >> 4) & 0x3;
        arg2 = state.mem[state.pc] & 0x7; /* only for add, nand */

        addressField = convertNum(state.mem[state.pc] & 0xF); /* for beq, lw, sw */
        state.pc++;
        if (opcode == ADD)
        {
            state.reg[arg2] = state.reg[arg0] + state.reg[arg1];
        }
        else if (opcode == NAND)
        {
            state.reg[arg2] = ~(state.reg[arg0] & state.reg[arg1]);
        }
        else if (opcode == LW)
        {
            if (state.reg[arg0] + addressField < 0 ||
                state.reg[arg0] + addressField >= NUMMEMORY)
            {

                printf("address out of bounds\n");
                exit(1);
            }
            state.reg[arg1] = state.mem[state.reg[arg0] + addressField];
            if (state.reg[arg0] + addressField > maxMem)
            {
                maxMem = state.reg[arg0] + addressField;
            }
        }
        else if (opcode == LWB)
        {
            state.base = arg0;
        }
        else if (opcode == SW)
        {
            if (state.reg[arg0] + addressField < 0 ||
                state.reg[arg0] + addressField >= NUMMEMORY)
            {
                printf("address out of bounds\n");  	 	 	 	exit(1);
            }
            state.mem[state.reg[arg0] + addressField] = state.reg[arg1];  	 	 	if (state.reg[arg0] + addressField > maxMem)
            {
                maxMem = state.reg[arg0] + addressField;
            }
        }
        else if (opcode == BEQ)
        {
            if (state.reg[arg0] == state.reg[arg1])
            {
                state.pc += addressField;
            }
        }
        else if (opcode == JMAE)
        {
            if (state.reg[arg0] >= state.reg[arg1])
            {
                state.pc += addressField;
            }
        }
        else if (opcode == JMLE)
        {
            if (state.reg[arg0] <= state.reg[arg1])
            {
                state.pc += addressField;
            }
        }
        else if (opcode == JALR)
        {
            state.reg[arg1] = state.pc;  	 	 	if (arg0 != 0)  	 	 	 	state.pc = state.reg[arg0];
            else
                state.pc = 0;
        }
        else if (opcode == NOOP)
        {
        }
        else if (opcode == DIV)
        {
            state.reg[arg2] = abs(state.reg[arg0] / state.reg[arg1]);
        }
        else if (opcode == XIDIV)
        {
            state.reg[arg2] = state.reg[arg0] / state.reg[arg1];  	 	 	int i = state.reg[arg0];  	 	 	state.reg[arg0] = state.reg[arg1];
            state.reg[arg1] = i;
        }
        else if (opcode == XADD)
        {
            state.reg[arg2] = state.reg[arg0] + state.reg[arg1];  	 	 	int i = state.reg[arg0];
            state.reg[arg0] = state.reg[arg1];
            state.reg[arg1] = i;
        }
        else if (opcode == XOR)
        {
            state.reg[arg2] = state.reg[arg0] ^ state.reg[arg1];
        }
        else if (opcode == AND)
        {
            state.reg[arg2] = state.reg[arg0] & state.reg[arg1];
        }
        else if (opcode == CMPL)
        {
            if (state.reg[arg0] < state.reg[arg1])
                state.reg[arg2] = 1;
            else
                state.reg[arg2] = 0;
        }
        else if (opcode == BT)
        {
            state.CF = (state.reg[arg0] >> state.reg[arg1]) & 1;
        }
        else if (opcode == SBB)
        {
            state.reg[arg2] = state.reg[arg0] - state.reg[arg1] - state.CF;
            // Встановлюємо CF в 1, якщо відбулася позичка (якщо regB або CF більше regA)  	 	 	state.CF = (state.reg[arg0] < state.reg[arg1] || state.reg[arg0] - state.CF < state.reg[arg1]) ? 1 : 
            0;
        }
        else if (opcode == RCR)
        {
            state.reg[arg2] = state.reg[arg0];
            for (int i = 0; i < state.reg[arg1]; i++)
            {
                int leastSignificantBit = state.reg[arg2] & 1;

                state.reg[arg2] = state.reg[arg2] >> 1;

                state.CF = leastSignificantBit;

                if (state.CF == 1)
                    state.reg[arg2] = state.reg[arg2] | (1 << 2);
            }
        }

        else if (opcode == DIVB)
        {
            state.reg[arg1] = state.reg[arg0] / state.reg[state.base];
            printf("ADress:%d %d %d\n", arg0, arg1, state.base);
        }
        else if (opcode == XORB)
        {
            state.reg[arg1] = state.reg[arg0] ^ state.reg[state.base];
            printf("ADress:%d %d %d\n", arg0, arg1, state.base);
        }
        else if (opcode == ANDB)
        {
            state.reg[arg1] = state.reg[arg0] & state.reg[state.base];
            printf("ADress:%d %d %d\n", arg0, arg1, state.base);
        }
        else if (opcode == HALT)
        {
            printf("machine halted\n");
            printf("total of %d instructions executed\n", instructions + 1);
            printf("final state of machine:\n");  	 	 	printState(&state);  	 	 	exit(0);
        }
        else
        {
            printf("error: illegal opcode 0x%x\n", opcode);  	 	 	exit(1);
        }
        state.reg[0] = 0;
    }
}

void printState(stateType* statePtr)
{
    int i;
    printf("\n@@@\nstate:\n"); printf("\tpc %d\n", statePtr->pc); printf("\tmemory:\n");
    for (i = 0; i < statePtr->numMemory; i++)
    {
        printf("\t\tmem[ %d ] %d\n", i, statePtr->mem[i]);
    } printf("\tregisters:\n"); for (i = 0; i < NUMREGS; i++)
    {
        printf("\t\treg[ %d ] %d\n", i, statePtr->reg[i]);
    }
    printf("\t\tbase = %d\n", statePtr->base);  	printf("\tflags:\n");  	printf("\t\tCF = %d\n", statePtr->CF);
    printf("end state\n");
}

int convertNum(int num)
{
    /* convert a 16-bit number into a 32-bit Sun integer */
    if (num & (1 << 15))
    {
        num -= (1 << 16);
    }
    return (num);
}
