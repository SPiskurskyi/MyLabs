#pragma once
#include "DataTypes.h"

class Generator
{
private:
    DataType* Data;
    vector<int> bufExprPostfixForm;
    vector<int> opStack, ifStack, loopStack, startStack;
    string outMsg;
    string type, typeL;
    string regA, regB, regD;
    int  arg0, arg1, retArg1, retArg2;
    void BeginASMFile(FILE* fout);
    void BeginCodeSegm(FILE* fout);

    void CheckPresent();

    void PrintData(FILE* f);

    void PrintADD(FILE* f);
    void PrintSUB(FILE* f);
    void PrintMUL(FILE* f);
    void PrintDIV(FILE* f);
    void PrintMOD(FILE* f);
    void PrintAND(FILE* f);
    void PrintOR(FILE* f);
    void PrintNOT(FILE* f);
    void PrintEQ(FILE* f);
    void PrintGE(FILE* f);
    void PrintLE(FILE* f);

    void PrintInput(FILE* f);
    void PrintOutput(FILE* f);

    void PrintEnding(FILE* f);

    bool Prioritet(TypeOfLex t, int  s);

    int ConvertToPostfixForm(int i);

    void GenASMCode(string str, FILE* f);

    void PrintCode(FILE* f);
public:
    Generator(DataType* Data);
    void GenerateCode(FILE* f);
};