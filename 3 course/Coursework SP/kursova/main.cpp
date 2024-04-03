#include "Analizer.h"
#include "ErrorsCheck.h"
#include "Generator.h"

FILE* InF, * OutF, * ErrorF;

int main(int argc, std::string* argv)
{
    DataType* Data = new DataType;
    Analizer A(Data);
    ErrorsCheck E(Data);
    Generator G(Data);
    printf("~~~TRANSLATOR~~~ (.%s files -> asm)\n", Data->ftype.c_str());
retry:

    if (argc != 2)
    {
        printf("Input file name > ");
        std::cin >> Data->InputFileName;
    }
    else
    {
        Data->InputFileName = argv->c_str();
    }

    if ((InF = fopen(Data->InputFileName.c_str(), "r")) == 0)
    {
        printf("Error: Can not open file: %s\n", Data->InputFileName.c_str());     
        goto retry;
    }

    char temp[4] = { '\0' };

    Data->InputFileName.copy(temp, 3, Data->InputFileName.size() - 3);

    if (std::string(temp) != Data->ftype)
    {
        printf("Error: Invalid file type: %s\n", Data->InputFileName.c_str());
        system("pause");
        free(Data);
        exit(1);
    }

    printf("Start translating file: %s\n", Data->InputFileName.c_str());
    int k = Data->InputFileName.size();
    while (k > 0)
    {
        if (Data->InputFileName[k] == '\\')
        {
            k++;
            break;
        }
        k--;
    }
    Data->OutputFileName = Data->InputFileName;
    Data->OutputFileName.erase(Data->InputFileName.size() - 4, Data->InputFileName.size());
    Data->OutputFileName.erase(0, k);

    printf("Output file: %s\n\n", std::string(Data->OutputFileName + ".asm").c_str());

    printf("Breaking into lexems are starting...\n");
    A.AnalisisLexems(InF);
    A.PrintLexemsInFile();
    printf("Breaking into lexems completed. There are %d lexems.\nReport file: lexems.txt\n\n", Data->LexTable.size());


    printf("Error checking are starting...\n");
    Data->numberErrors = E.ErrorChecking();
    printf("Error checking is complete. There is(are) %d errors.\nReport file: errors.txt\n\n", Data->numberErrors);

    if (Data->numberErrors != 0)
    {
        printf("Translation can not be continued. Errors were found. Please correct the errors and try again.\n");
    }
    else
    {
        if ((OutF = fopen(std::string(Data->OutputFileName + ".asm").c_str(), "w")) == 0)
        {
            printf("Error: Can not create file: %s\n", std::string(Data->OutputFileName + ".asm").c_str());
            system("pause");
            free(Data);
            exit(1);
        }
        printf("Code generation is starting...\n");
        G.GenerateCode(OutF);
        printf("Code generation is finish.\n\n");
        fclose(OutF);
        if (directory_exists("masm32"))
        {
            system(std::string("masm32\\bin\\ml /c /coff " + Data->OutputFileName + ".asm").c_str());
            system(std::string("masm32\\bin\\Link /SUBSYSTEM:WINDOWS " + Data->OutputFileName + ".obj").c_str());
            
        }
        else
        {
            printf("WARNING!\n");
            printf("Can't compile asm file, because masm32 doesn't exist.\n");
        }

        printf("\nDone!\n");
    }
    system("pause");
    free(Data);
    return 0;
}