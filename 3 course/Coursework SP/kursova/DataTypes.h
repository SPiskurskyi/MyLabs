#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <Windows.h>
#include <io.h>

#define IsOperation(k) (k < 12)

using namespace std;

enum TypeOfLex
{
    LAdd,
    LSub,
    LMul,
    LDiv,
    LMod,
    LEqu,
    LNotEqu,
    LGreate,
    LLess,
    LNot,
    LAnd,
    LOr,

    LBegProg,
    LProgram,
    LProgramName,
    LStart,
    LVariable,
    LVarType,
    LIdentifier,
    LStop,

    LScan,
    LPrint,

    LIf,
    LElse,
    LDo,
    LWhile,

    LNewValue,

    LDLine,
    LLBraket,
    LRBraket,
    LNumber,
    LSeparator,
    LComma,
    LEOF,
    LLComentar,
    LRComentar,
    LUnknown
};

struct LexAndName
{
    TypeOfLex type;
    std::string name;
};


typedef struct Lexem
{
    string name;
    int value;
    int line;
    TypeOfLex type;
} Lexema;

typedef struct L
{
    vector<Lexema> LexTable;		

    vector<string> IdTable;		
    string ftype = "p15";
    string TName = "xxxxxx";
    vector<LexAndName> LexName =
    {
        {LAdd,"+"},
        {LSub,"-"},
        {LMul,"Mul" },
        {LDiv,"Div"},
        {LMod,"Mod"},
        {LEqu,"="},
        {LNotEqu,"<>"},
        {LGreate,">"},
        {LLess,"<"},
        {LNot,"!"},
        {LAnd,"And"},
        {LOr,"Or"},

        {LBegProg,"#"},
        {LProgram,"Program"},
        {LProgramName,""},
        {LStart,"Start"},
        {LVariable,"Variable"},
        {LVarType,"Integer"},
        {LIdentifier,""},
        {LStop,"Stop"},

        {LScan,"Scan"},
        {LPrint,"Print"},

        {LIf,"If"},
        {LElse,"Else"},
        {LDo,"Do"},
        {LWhile,"While"},

        {LNewValue,"<<"},

        {LLBraket,"("},
        {LRBraket,")"},
        {LDLine,"_"},
        {LNumber,""},
        {LSeparator,";"},
        {LComma,","},
        {LLComentar,"!!"},
        {LRComentar,""},
        {LEOF,"EndFile"}
    };

    bool IsPresentInput,
        IsPresentOutput,
        IsPresentAdd,
        IsPresentSub,
        IsPresentMul,
        IsPresentDiv,
        IsPresentMod,
        IsPresentAnd,
        IsPresentOr,
        IsPresentNot,
        IsPresentEqu,
        IsPresentGreate,
        IsPresentLess;

    bool EnableProgN = 1, PosLStart = 0;

    int numberErrors;

    std::string InputFileName;
    std::string OutputFileName;
}DataType;

bool directory_exists(const std::string& directory);