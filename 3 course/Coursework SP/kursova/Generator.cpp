#include "Generator.h"

void Generator::BeginASMFile(FILE* fout)
{
    fprintf(fout, ".386\n.model flat, stdcall\noption casemap :none\n");
    fprintf(fout, "include masm32\\include\\windows.inc\ninclude masm32\\include\\kernel32.inc\ninclude masm32\\include\\masm32.inc\ninclude masm32\\include\\user32.inc\ninclude masm32\\include\\msvcrt.inc\n");
    fprintf(fout, "includelib masm32\\lib\\kernel32.lib\nincludelib masm32\\lib\\masm32.lib\nincludelib masm32\\lib\\user32.lib\nincludelib masm32\\lib\\msvcrt.lib\n");
    fprintf(fout, "\n.DATA");
}

void Generator::BeginCodeSegm(FILE* fout)
{
    fprintf(fout, "\n.CODE\n");
    fprintf(fout, "start:\n");
    fprintf(fout, "invoke AllocConsole\n");
    fprintf(fout, "invoke GetStdHandle, STD_INPUT_HANDLE\n");
    fprintf(fout, "mov hConsoleInput, EAX\n");
    fprintf(fout, "invoke GetStdHandle, STD_OUTPUT_HANDLE\n");
    fprintf(fout, "mov hConsoleOutput, EAX\n");
}

void Generator::CheckPresent()
{
    for (int i = 0; Data->LexTable[i].type != LEOF; ++i)
    {
        if (Data->LexTable[i].type == LScan) Data->IsPresentInput = true;
        if (Data->LexTable[i].type == LPrint) Data->IsPresentOutput = true;
        if (Data->LexTable[i].type == LAdd) Data->IsPresentAdd = true;
        if (Data->LexTable[i].type == LSub) Data->IsPresentSub = true;
        if (Data->LexTable[i].type == LMul) Data->IsPresentMul = true;
        if (Data->LexTable[i].type == LDiv) Data->IsPresentDiv = true;
        if (Data->LexTable[i].type == LMod) Data->IsPresentMod = true;
        if (Data->LexTable[i].type == LAnd) Data->IsPresentAnd = true;
        if (Data->LexTable[i].type == LOr) Data->IsPresentOr = true;
        if (Data->LexTable[i].type == LNot || Data->LexTable[i].type == LNotEqu) Data->IsPresentNot = true;
        if (Data->LexTable[i].type == LEqu || Data->LexTable[i].type == LNotEqu) Data->IsPresentEqu = true;
        if (Data->LexTable[i].type == LGreate) Data->IsPresentGreate = true;
        if (Data->LexTable[i].type == LLess) Data->IsPresentLess = true;
        if (Data->IsPresentInput &&
            Data->IsPresentOutput &&
            Data->IsPresentAdd &&
            Data->IsPresentSub &&
            Data->IsPresentMul &&
            Data->IsPresentDiv &&
            Data->IsPresentMod &&
            Data->IsPresentAnd &&
            Data->IsPresentOr &&
            Data->IsPresentNot &&
            Data->IsPresentEqu &&
            Data->IsPresentGreate &&
            Data->IsPresentLess) break;
    }
}

void Generator::PrintData(FILE* f)
{
    fputs("\n;===User Data==============\n", f);
    for (int i = 0; i < Data->IdTable.size(); ++i)
    {
        fprintf(f, "\t%s\t%s\t00h\n", Data->IdTable[i].c_str(), type.c_str());
    }
    fputs("\n;===Addition Data===========================================\n", f);
    fputs("\thConsoleInput\tdd\t?\n", f);
    fputs("\thConsoleOutput\tdd\t?\n", f);
    fputs("\tErrorMessage\tdb\t\"Error: division by zero\", 0\n", f);
    fputs("\tInputBuf\tdb\t15 dup (?)\n", f);
    fprintf(f, "\tInMessage\tdb\t\"%s: \", 0\n", Data->LexName[LScan].name.c_str());
    fprintf(f, "\tOutMessage\tdb\t\"%s: %s", Data->LexName[LPrint].name.c_str(), outMsg.data());
    fputs("\tResMessage\tdb\t20 dup (?)\n", f);
    fputs("\tNumberOfCharsRead\tdd\t?\n", f);
    fputs("\tNumberOfCharsWrite\tdd\t?\n", f);
    fputs("\tmsg1310\tdw\t13,10\n", f);
    fputs("\tbuf\tdd\t0\n", f);
}

void Generator::PrintADD(FILE* f)
{
    fputs("\n;===Procedure Add=========================\n", f);
    fputs("Add_ PROC\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tadd %s, [esp+%d]\n", regA.c_str(), arg1);
    fprintf(f, "\tret %d\n", retArg2);
    fputs("Add_ ENDP\n", f);
    fputs(";=========================================\n\n", f);
}

void Generator::PrintSUB(FILE* f)
{
    fputs("\n;===Procedure Sub=========================\n", f);
    fputs("Sub_ PROC\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tsub %s, [esp+%d]\n", regA.c_str(), arg1);
    fprintf(f, "\tret %d\n", retArg2);
    fputs("Sub_ ENDP\n", f);
    fputs(";=========================================\n\n", f);
}

void Generator::PrintMUL(FILE* f)
{
    fputs("\n;===Procedure Mul=========================\n", f);
    fputs("Mul_ PROC\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tmov %s, [esp+%d]\n", regB.c_str(), arg1);
    fprintf(f, "\timul %s\n", regB.c_str());
    fprintf(f, "\tret %d\n", retArg2);
    fputs("Mul_ ENDP\n", f);
    fputs(";=========================================\n\n", f);
}

void Generator::PrintDIV(FILE* f)
{
    fputs("\n;===Procedure Div=========================\n", f);
    fputs("Div_ PROC\n", f);
    fputs("\tpushf\n", f);
    fputs("\tpop cx\n\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg1);
    fprintf(f, "\tcmp %s, 0\n", regA.c_str());
    fputs("\tjne end_check\n", f);
    fputs("\tinvoke WriteConsoleA,hConsoleOutput,ADDR msg1310,SIZEOF msg1310,ADDR NumberOfCharsWrite,0\n", f);
    fputs("\tinvoke WriteConsoleA, hConsoleOutput, ADDR ErrorMessage, SIZEOF ErrorMessage, ADDR NumberOfCharsWrite, 0\n", f);
    fputs("\tjmp exit_label\n", f);
    fputs("end_check:\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tcmp %s, 0\n", regA.c_str());
    fputs("\tjge gr\n", f);
    fputs("lo:\n", f);
    fprintf(f, "\tmov %s, -1\n", regD.c_str());
    fputs("\tjmp less_fin\n", f);
    fputs("gr:\n", f);
    fprintf(f, "\tmov %s, 0\n", regD.c_str());
    fputs("less_fin:\n\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tmov %s, [esp+%d]\n", regB.c_str(), arg1);
    fprintf(f, "\tidiv %s\n\n", regB.c_str());
    fputs("\tpush cx\n", f);
    fputs("\tpopf\n", f);
    fprintf(f, "\tret %d\n", retArg2);
    fputs("Div_ ENDP\n", f);
    fputs(";=========================================\n\n", f);
}

void Generator::PrintMOD(FILE* f)
{
    fputs("\n;===Procedure Mod=========================\n", f);
    fputs("Mod_ PROC\n", f);
    fputs("\tpushf\n", f);
    fputs("\tpop cx\n\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tcmp %s, 0\n", regA.c_str());
    fputs("\tjne end_check\n", f);
    fputs("\tinvoke WriteConsoleA,hConsoleOutput,ADDR msg1310,SIZEOF msg1310,ADDR NumberOfCharsWrite,0\n", f);
    fputs("\tinvoke WriteConsoleA, hConsoleOutput, ADDR ErrorMessage, SIZEOF ErrorMessage, ADDR NumberOfCharsWrite, 0\n", f);
    fputs("\tjmp exit_label\n", f);
    fputs("end_check:\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tcmp %s, 0\n", regA.c_str());
    fputs("\tjge gr\n", f);
    fputs("lo:\n", f);
    fprintf(f, "\tmov %s, -1\n", regD.c_str());
    fputs("\tjmp less_fin\n", f);
    fputs("gr:\n", f);
    fprintf(f, "\tmov %s, 0\n", regD.c_str());
    fputs("less_fin:\n\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tmov %s, [esp+%d]\n", regB.c_str(), arg1);
    fprintf(f, "\tidiv %s\n\n", regB.c_str());
    fprintf(f, "\tmov %s, %s\n\n", regA.c_str(), regD.c_str());
    fputs("\tpush cx\n", f);
    fputs("\tpopf\n", f);
    fprintf(f, "\tret %d\n", retArg2);
    fputs("Mod_ ENDP\n", f);
    fputs(";=========================================\n\n", f);
}

void Generator::PrintAND(FILE* f)
{
    fputs("\n;===Procedure And=========================\n", f);
    fputs("And_ PROC\n", f);
    fputs("\tpushf\n", f);
    fputs("\tpop cx\n\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tcmp %s, 0\n", regA.c_str());
    fputs("\tjnz and_t1\n", f);
    fputs("\tjz and_false\n", f);
    fputs("and_t1:\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg1);
    fprintf(f, "\tcmp %s, 0\n", regA.c_str());
    fputs("\tjnz and_true\n", f);
    fputs("and_false:\n", f);
    fprintf(f, "\tmov %s, 0\n", regA.c_str());
    fputs("\tjmp and_fin\n", f);
    fputs("and_true:\n", f);
    fprintf(f, "\tmov %s, 1\n", regA.c_str());
    fputs("and_fin:\n\n", f);
    fputs("\tpush cx\n", f);
    fputs("\tpopf\n", f);
    fprintf(f, "\tret %d\n", retArg2);
    fputs("And_ ENDP\n", f);
    fputs(";=========================================\n\n", f);
}

void Generator::PrintOR(FILE* f)
{
    fputs("\n;===Procedure Or==========================\n", f);
    fputs("Or_ PROC\n", f);
    fputs("\tpushf\n", f);
    fputs("\tpop cx\n\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tcmp %s, 0\n", regA.c_str());
    fputs("\tjnz or_true\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg1);
    fprintf(f, "\tcmp %s, 0\n", regA.c_str());
    fputs("\tjnz or_true\n", f);
    fprintf(f, "\tmov %s, 0\n", regA.c_str());
    fputs("\tjmp or_fin\n", f);
    fputs("or_true:\n", f);
    fprintf(f, "\tmov %s, 1\n", regA.c_str());
    fputs("or_fin:\n\n", f);
    fputs("\tpush cx\n", f);
    fputs("\tpopf\n", f);
    fprintf(f, "\tret %d\n", retArg2);
    fputs("Or_ ENDP\n", f);
    fputs(";=========================================\n\n", f);
}

void Generator::PrintNOT(FILE* f)
{
    fputs("\n;===Procedure Not=========================\n", f);
    fputs("Not_ PROC\n", f);
    fputs("\tpushf\n", f);
    fputs("\tpop cx\n\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg1);
    fprintf(f, "\tcmp %s, 0\n", regA.c_str());
    fputs("\tjne not_false\n", f);
    fprintf(f, "\tmov %s, 1\n", regA.c_str());
    fputs("\tjmp not_fin\n", f);
    fputs("not_false:\n", f);
    fprintf(f, "\tmov %s, 0\n", regA.c_str());
    fputs("not_fin:\n\n", f);
    fputs("\tpush cx\n", f);
    fputs("\tpopf\n", f);
    fprintf(f, "\tret %d\n", retArg1);
    fputs("Not_ ENDP\n", f);
    fputs(";=========================================\n\n", f);
}

void Generator::PrintEQ(FILE* f)
{
    fputs("\n;===Procedure Eq==========================\n", f);
    fputs("Eq_ PROC\n", f);
    fputs("\tpushf\n", f);
    fputs("\tpop cx\n\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tcmp %s, [esp+%d]\n", regA.c_str(), arg1);
    fputs("\tjne not_eq\n", f);

    fprintf(f, "\tmov %s, 1\n", regA.c_str());
    fputs("\tjmp eq_fin\n", f);
    fputs("not_eq:\n", f);
    fprintf(f, "\tmov %s, 0\n", regA.c_str());
    fputs("eq_fin:\n\n", f);
    fputs("\tpush cx\n", f);
    fputs("\tpopf\n", f);
    fprintf(f, "\tret %d\n", retArg2);
    fputs("Eq_ ENDP\n", f);
    fputs(";=========================================\n\n", f);
}

void Generator::PrintGE(FILE* f)
{
    fputs("\n;===Procedure Greate======================\n", f);
    fputs("Greate_ PROC\n", f);
    fputs("\tpushf\n", f);
    fputs("\tpop cx\n\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tcmp %s, [esp+%d]\n", regA.c_str(), arg1);
    fputs("\tjle lov\n", f);
    fprintf(f, "\tmov %s, 1\n", regA.c_str());
    fputs("\tjmp gr_fin\n", f);
    fputs("lov:\n", f);
    fprintf(f, "\tmov %s, 0\n", regA.c_str());
    fputs("gr_fin:\n\n", f);
    fputs("\tpush cx\n", f);
    fputs("\tpopf\n", f);
    fprintf(f, "\tret %d\n", retArg2);
    fputs("Greate_ ENDP\n", f);
    fputs(";=========================================\n\n", f);
}

void Generator::PrintLE(FILE* f)
{
    fputs("\n;===Procedure Less========================\n", f);
    fputs("Less_ PROC\n", f);
    fputs("\tpushf\n", f);
    fputs("\tpop cx\n\n", f);
    fprintf(f, "\tmov %s, [esp+%d]\n", regA.c_str(), arg0);
    fprintf(f, "\tcmp %s, [esp+%d]\n", regA.c_str(), arg1);
    fputs("\tjge gr\n", f);
    fputs("lo:\n", f);
    fprintf(f, "\tmov %s, 1\n", regA.c_str());
    fputs("\tjmp less_fin\n", f);
    fputs("gr:\n", f);
    fprintf(f, "\tmov %s, 0\n", regA.c_str());
    fputs("less_fin:\n\n", f);
    fputs("\tpush cx\n", f);
    fputs("\tpopf\n", f);
    fprintf(f, "\tret %d\n", retArg2);
    fputs("Less_ ENDP\n", f);
    fputs(";=========================================\n\n", f);
}

void Generator::PrintInput(FILE* f)
{
    fputs("\n;===Procedure Input==========================================================================\n", f);
    fputs("Input PROC\n", f);
    fputs("invoke WriteConsoleA,hConsoleOutput,ADDR msg1310,SIZEOF msg1310,ADDR NumberOfCharsWrite,0\n", f);
    fputs("invoke WriteConsoleA,hConsoleOutput,ADDR InMessage,SIZEOF InMessage,ADDR NumberOfCharsWrite,0\n", f);
    fputs("invoke ReadConsoleA,hConsoleInput,ADDR InputBuf,11,ADDR NumberOfCharsRead,0\n", f);
    fputs("invoke crt_atoi, addr InputBuf\n", f);
    fputs("ret\n", f);
    fputs("Input ENDP\n", f);
    fputs(";============================================================================================\n\n", f);
}

void Generator::PrintOutput(FILE* f)
{
    fputs("\n;===Procedure Output=========================================================================\n", f);
    fprintf(f, "Output PROC, value:%s\n", typeL.c_str());
    fputs("invoke WriteConsoleA,hConsoleOutput,ADDR msg1310,SIZEOF msg1310,ADDR NumberOfCharsWrite,0\n", f);
    fputs("invoke wsprintf, addr ResMessage, addr OutMessage, value\n", f);
    fputs("invoke WriteConsoleA,hConsoleOutput,ADDR ResMessage,eax,ADDR NumberOfCharsWrite,0\n", f);
    fputs("ret\n", f);
    fputs("Output ENDP\n", f);
    fputs(";============================================================================================\n\n", f);
}

void Generator::PrintEnding(FILE* f)
{
    fputs("exit_label:\n", f);
    fputs("invoke WriteConsoleA,hConsoleOutput,ADDR msg1310,SIZEOF msg1310,ADDR NumberOfCharsWrite,0\n", f);
    fputs("invoke ReadConsoleA,hConsoleInput,ADDR InputBuf,1,ADDR NumberOfCharsRead,0\n", f);
    fputs("invoke ExitProcess, 0\n", f);
    if (Data->IsPresentInput) PrintInput(f);
    if (Data->IsPresentOutput) PrintOutput(f);
    if (Data->IsPresentAdd) PrintADD(f);
    if (Data->IsPresentSub) PrintSUB(f);
    if (Data->IsPresentMul) PrintMUL(f);
    if (Data->IsPresentDiv) PrintDIV(f);
    if (Data->IsPresentMod) PrintMOD(f);
    if (Data->IsPresentAnd) PrintAND(f);
    if (Data->IsPresentOr) PrintOR(f);
    if (Data->IsPresentNot) PrintNOT(f);
    if (Data->IsPresentEqu) PrintEQ(f);
    if (Data->IsPresentGreate) PrintGE(f);
    if (Data->IsPresentLess) PrintLE(f);
    fputs("end start\n", f);
}

bool Generator::Prioritet(TypeOfLex t, int s)
{
    int arr[] = { 4,4,5,5,5,2,2,3,3,6,1,1,7,7,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    return arr[t] > arr[Data->LexTable[s].type];
}

int Generator::ConvertToPostfixForm(int i)
{
    vector <int> Stack;
    int n = 0;
    for (; ((Data->LexTable[i + n].type != LSeparator) && (Data->LexTable[i + n + 2].type != LStart)); ++n);
    int k = i + n;
    for (; i <= k; i++)
    {
        TypeOfLex in;
        in = Data->LexTable[i].type;

        if ((in == LIdentifier) || (in == LNumber))
        {
            bufExprPostfixForm.push_back(i);
        }
        else if (IsOperation(in))
        {
            if (Stack.empty() || Prioritet(in, Stack.back()))
            {
                Stack.push_back(i);
            }
            else
            {
                if (Data->LexTable[Stack.back()].type != LLBraket)
                {
                    do
                    {
                        bufExprPostfixForm.push_back(Stack.back());
                        Stack.pop_back();
                        if (Stack.empty())
                        {
                            break;
                        }
                    } while ((!(Prioritet(in, Stack.back()))) && (!(Stack.empty())) && (Data->LexTable[Stack.back()].type != LLBraket));
                }
                Stack.push_back(i);
            }
        }
        if (in == LLBraket)
        {
            Stack.push_back(i);
            bufExprPostfixForm.push_back(i);
        }
        if (in == LRBraket)
        {
            for (; (Data->LexTable[Stack.back()].type != LLBraket);)
            {
                bufExprPostfixForm.push_back(Stack.back());
                Stack.pop_back();
            }
            Stack.pop_back();
            bufExprPostfixForm.push_back(i);
        }
    }
    for (; !(Stack.empty());)
    {
        bufExprPostfixForm.push_back(Stack.back());
        Stack.pop_back();
    }
    return k;
}

void Generator::GenASMCode(string  str, FILE* f)
{
    int n;
    for (n = 0; n < bufExprPostfixForm.size(); ++n)
    {
        if ((!IsOperation(Data->LexTable[bufExprPostfixForm[n]].type)) && (Data->LexTable[bufExprPostfixForm[n]].type != LNot))
        {
            if (Data->LexTable[bufExprPostfixForm[n]].type == LIdentifier)
                fprintf(f, "\tpush %s\n", Data->LexTable[bufExprPostfixForm[n]].name.c_str());
            else if (Data->LexTable[bufExprPostfixForm[n]].type == LNumber)
                fprintf(f, "\tpush %s ptr %d\n", typeL.data(), Data->LexTable[bufExprPostfixForm[n]].value);
        }
        else
        {
            switch (Data->LexTable[bufExprPostfixForm[n]].type)
            {
            case LAdd:
                fputs("\tcall Add_\n", f);
                break;
            case LSub:
                fputs("\tcall Sub_\n", f);
                break;
            case LMul:
                fputs("\tcall Mul_\n", f);
                break;
            case LDiv:
                fputs("\tcall Div_\n", f);
                break;
            case LMod:
                fputs("\tcall Mod_\n", f);
                break;
            case LAnd:
                fputs("\tcall And_\n", f);
                break;
            case LOr:
                fputs("\tcall Or_\n", f);
                break;
            case LNot:
                fputs("\tcall Not_\n", f);
                break;
            case LEqu:
                fputs("\tcall Eq_\n", f); break;
            case LNotEqu:
                fputs("\tcall Eq_\n", f);
                fprintf(f, "\tpush %s\n", regA.c_str());
                fputs("\tcall Not_\n", f);
                break;
            case LLess:
                fputs("\tcall Less_\n", f); break;
            case LGreate:
                fputs("\tcall Greate_\n", f); break;
            }
            fprintf(f, "\tpush %s\n", regA.c_str());
        }
    }
    if (!str.empty() && bufExprPostfixForm.size() == 1)
        fprintf(f, "\tpop %s\n", regA.c_str());
    bufExprPostfixForm.clear();
    if (!str.empty())
        fprintf(f, "\tmov %s, %s\n", str.c_str(), regA.c_str());
}

void Generator::PrintCode(FILE* f)
{
    int loopLabelIndex = 0;
    int ifLabelIndex = 0;
    Lexema l;
    int i = 0;

    do
    {
        ++i;
    } while (Data->LexTable[i].type != LVarType);
    ++i;
    if (Data->LexTable[i].type == LVarType)
    {
        do
        {
            i++;
        } while (Data->LexTable[i].type != LSeparator);
        i++;
    }

    for (;; ++i)
    {
        l = Data->LexTable[i];

        if (l.type == LEOF)
        {
            break;
        }

        if (l.type == LIf)
        {
            int count = 0;
            ifLabelIndex++;
            ifStack.push_back(ifLabelIndex);
            opStack.push_back(0);
            i = ConvertToPostfixForm(i + 1);
            GenASMCode("", f);
            fprintf(f, "\tcmp %s, 0\n", regA.c_str());
            for (size_t j = i + 1; Data->LexTable[j].type != LEOF; j++)
            {
                if (Data->LexTable[j].type == LStart)
                {
                    count++;
                }
                if (Data->LexTable[j].type == LElse && count == 1)
                {
                    fprintf(f, "je ifLabel%d\n", ifLabelIndex);
                    break;
                }
                if (Data->LexTable[j].type == LStop && count == 1)
                {
                    fprintf(f, "\tje endIf%d\n", ifLabelIndex);
                    break;
                }
                else if (Data->LexTable[j].type == LStop && count > 1)
                {
                    count--;
                }
            }
        }
        if (l.type == LElse)
        {
            fprintf(f, "\tjmp endIf%d\n", ifStack.back());
            fprintf(f, "ifLabel%d:\n", ifStack.back());
        }
        if (l.type == LStop && Data->LexTable[i + 1].type != LEOF)
        {
            if (!opStack.back())
            {
                fprintf(f, "endIf%d:\n", ifStack.back());
                ifStack.pop_back();
            }
            opStack.pop_back();
        }

        if (l.type == LDo)
        {
            fprintf(f, "whileStart%d:\n", ++loopLabelIndex);
            loopStack.push_back(loopLabelIndex);
        }

        if (l.type == LWhile)
        {
            int bufi;
            bufi = i;
            i = ConvertToPostfixForm(i + 1);	
            if (i < 0)
            {
                i = -i;
                puts("IE\n");
                continue;
            }
            GenASMCode("", f);
            fprintf(f, "\tcmp %s, 1\n", regA.c_str());
            fprintf(f, "\tjne whileEnd%d\n", loopStack.back());
            fprintf(f, "\tjmp whileStart%d\n", loopStack.back());
            fprintf(f, "whileEnd%d:\n", loopStack.back());
            loopStack.pop_back();
        }

        if (l.type == LPrint)
        {
            i = ConvertToPostfixForm(i + 1);
            GenASMCode("", f);
            fputs("\tcall Output\n", f);
        }
        if (l.type == LScan)
        {
            fputs("\tcall Input\n", f);
            fprintf(f, "\tmov %s, %s\n", Data->LexTable[i + 2].name.c_str(), regA.c_str());
            i += 4;
        }
        if (l.type == LNewValue)
        {
            int bufi = i;
            i = ConvertToPostfixForm(i + 1);
            GenASMCode(Data->LexTable[bufi - 1].name, f);
        }
    }
}

Generator::Generator(DataType* Data) : Data(Data)
{   
        type = "dd"; typeL = "dword";
        regA = "eax"; regB = "ebx"; regD = "edx";
        arg0 = 8; arg1 = 4; retArg1 = 4; retArg2 = 8;
        outMsg = "%d\", 0\n";    
}

void Generator::GenerateCode(FILE* f)
{
    BeginASMFile(f);
    CheckPresent();
    PrintData(f);
    BeginCodeSegm(f);

    PrintCode(f);

    PrintEnding(f);
}