/*
 * Instruction-level simulator for the LC
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMMEMORY 67108864 /* maximum number of words in memory */
#define NUMREGS 256 /* number of machine registers */
#define MAXLINELENGTH 1000

#define START_OPCODE 43
#define START_ARG_A 35
#define START_ARG_B 27

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
#define ROR 12
#define OR 13
//Керування операції
#define JMA 14
#define JMNB 15
//Регістр знаку
#define CMP 16
#define JL 17
#define JGE 18

typedef struct stateStruct {
	int pc;
	int mem[NUMMEMORY];
	int reg[NUMREGS];
	int numMemory;
	int CF;
	int SF;
	int ZF;
} stateType;

void printState(stateType*);
void run(stateType);
int convertNum(int);

int main(int argc, char* argv[])
{
	int i;
	char line[MAXLINELENGTH];
	stateType state;
	FILE* filePtr;

	if (argc != 2) {
		printf("error: usage: %s <machine-code file>\n", argv[0]);
		exit(1);
	}

	/* initialize memories and registers */
	for (i = 0; i < NUMMEMORY; i++) {
		state.mem[i] = 0;
	}
	for (i = 0; i < NUMREGS; i++) {
		state.reg[i] = 0;
	}

	state.pc = 0;
	state.CF = 0;
	state.SF = 0;
	state.ZF = 0;

	/* read machine-code file into instruction/data memory (starting at
	address 0) */

	filePtr = fopen(argv[1], "r");
	if (filePtr == NULL) {
		printf("error: can't open file %s\n", argv[1]);
		perror("fopen");
		exit(1);
	}

	for (state.numMemory = 0; fgets(line, MAXLINELENGTH, filePtr) != NULL;
		state.numMemory++) {
		if (state.numMemory >= NUMMEMORY) {
			printf("exceeded memory size\n");
			exit(1);
		}
		if (sscanf(line, "%d", state.mem + state.numMemory) != 1) {
			printf("error in reading address %d\n", state.numMemory);
			exit(1);
		}
		printf("memory[%d]=%d\n", state.numMemory, state.mem[state.numMemory]);
	}

	printf("\n");

	/* run never returns */
	run(state);

	return(0);
}

void run(stateType state)
{
	int regA, regB, destReg, offSet;
	int instructions = 0;
	int opcode;
	int instruction;
	int maxMem = -1;	/* highest memory address touched during run */

	printf("ssol operations:\n");
	for (; 1; instructions++) { /* infinite loop, exits when it executes halt */
		printState(&state);

		if (state.pc < 0 || state.pc >= NUMMEMORY) {
			printf("pc went out of the memory range\n");
			exit(1);
		}

		maxMem = (state.pc > maxMem) ? state.pc : maxMem;

		/* this is to make the following code easier to read */
		instruction = state.mem[state.pc];
		opcode = state.mem[state.pc] >> START_OPCODE;
		regA = (state.mem[state.pc] >> START_ARG_A) & 0xFF;
		regB = (state.mem[state.pc] >> START_ARG_B) & 0xFF;
		destReg = state.mem[state.pc] & 0xFF; /* only for add, nand */ 
		offSet = convertNum(state.mem[state.pc] & 0x3FFFFFF); /* for beq, jl, jge, lw, sw */
		
		printf("opcode=%d, regA=%d, regB=%d, destReg=%d\n", opcode, regA, regB, destReg);

		state.pc++;

		if (opcode == ADD) {
			state.reg[destReg] = state.reg[regA] + state.reg[regB];
		}
		else if (opcode == NAND) {
			state.reg[destReg] = ~(state.reg[regA] & state.reg[regB]);
		}
		else if (opcode == LW) {
			if (state.reg[regA] + offSet < 0 ||
				state.reg[regA] + offSet >= NUMMEMORY) {
				printf("address out of bounds\n");
				exit(1);
			}
			state.reg[regB] = state.mem[state.reg[regA] + offSet];
			if (state.reg[regA] + offSet > maxMem) {
				maxMem = state.reg[regA] + offSet;
			}
		}
		else if (opcode == SW) {
			if (state.reg[regA] + offSet < 0 ||
				state.reg[regA] + offSet >= NUMMEMORY) {
				printf("address out of bounds\n");
				exit(1);
			}
			state.mem[state.reg[regA] + offSet] = state.reg[regB];
			if (state.reg[regA] + offSet > maxMem) {
				maxMem = state.reg[regA] + offSet;
			}
		}
		else if (opcode == BEQ) {
			if (state.reg[regA] == state.reg[regB]) {
				state.pc += offSet;
			}
		}
		else if (opcode == JALR) {
			state.reg[regB] = state.pc;
			if (regA != 0)
				state.pc = state.reg[regA];
			else
				state.pc = 0;
		}
		else if (opcode == MUL) {
			state.reg[destReg] = state.reg[regA] * state.reg[regB];
		}
		else if (opcode == DEC) {
			state.reg[regA]--;
		}
		else if (opcode == XDIV) {
			state.reg[destReg] = abs(state.reg[regA]) / abs(state.reg[regB]);
			state.reg[regA] = state.reg[regA] ^ state.reg[regB];
			state.reg[regB] = state.reg[regB] ^ state.reg[regA];
			state.reg[regA] = state.reg[regA] ^ state.reg[regB];
		}
		else if (opcode == XIMUL) {
			state.reg[destReg] = state.reg[regA] * state.reg[regB];
			state.reg[regA] = state.reg[regA] ^ state.reg[regB];
			state.reg[regB] = state.reg[regB] ^ state.reg[regA];
			state.reg[regA] = state.reg[regA] ^ state.reg[regB];
		}
		else if (opcode == SHL) {
			state.reg[destReg] = state.reg[regA] >> state.reg[regB];
		}
		else if (opcode == ROR) {
			int amount = state.reg[regB] % 64; // Обмежуємо зсув до діапазону 0-63

			state.reg[destReg] = (state.reg[regA] << amount) | (state.reg[regA] >> (64 - amount));
		}
		else if (opcode == OR) {
			state.reg[destReg] = state.reg[regA] | state.reg[regB];
		}
		else if (opcode == JMA) {
			if (abs(state.reg[regA]) > abs(state.reg[regB])) {
				state.pc += offSet;
			}
		}
		else if (opcode == JMNB) {
			if (!(abs(state.reg[regA]) < abs(state.reg[regB]))) {
				state.pc += offSet;
			}
		}
		else if (opcode == CMP) {
			if (state.reg[regA] < state.reg[regB]) {
				state.CF = 1;
				state.SF = 1;
				state.ZF = 0;
			}
			else if (state.reg[regA] = state.reg[regB]) {
				state.CF = 0;
				state.SF = 0;
				state.ZF = 1;
			}
			else {
				state.CF = 0;
				state.SF = 0;
				state.ZF = 0;
			}
		}
		else if (opcode == JL) {
			if (state.SF == 1) {
				state.pc += offSet;
			}
		}
		else if (opcode == JGE) {
			if (state.SF == 1) {
			state.pc += offSet;
		}
		}
		else if (opcode == HALT) {
			printf("machine halted\n");
			printf("total of %d instructions executed\n", instructions + 1);
			printf("final state of machine:\n");
			printState(&state);
			exit(0);
		}
		else {
			printf("error: illegal opcode 0x%x\n", opcode);
			exit(1);
		}
		state.reg[0] = 0;
	}
}

void printState(stateType* statePtr)
{
	int i;
	printf("\n@@@\nstate:\n");
	printf("\tpc %d\n", statePtr->pc);
	printf("\tmemory:\n");
	for (i = 0; i < statePtr->numMemory; i++) {
		printf("\t\tmem[ %d ] %d\n", i, statePtr->mem[i]);
	}
	printf("\tregisters:\n");
	for (i = 0; i < NUMREGS; i++) {
		printf("\t\treg[ %d ] %d\n", i, statePtr->reg[i]);
	}

	
	printf("\tFlags:\n");
	printf("CF = %d\n", statePtr->CF);
	printf("SF = %d\n", statePtr->SF);
	printf("ZF = %d\n", statePtr->ZF);
	printf("end state\n");
}

int
convertNum(int num)
{
	/* convert a 16-bit number into a 32-bit Sun integer */
	if (num & (1 << 15)) {
		num -= (1 << 16);
	}
	return(num);
}
