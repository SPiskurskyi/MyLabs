#define _CRT_SECURE_NO_WARNINGS
#include "Electric_kettle.h"

int main()
{
    char* name = new char[128];
    string temp;
    strcpy(name, "Bosch");
    Electric_kettle ek(name,10);
    ek.On();
    cout << "Choose mode(Normal, Turbo, Eco) - ";
    cin >> temp;
    ek.Execute(temp);
    ek.Off();
    cout << "Choose mode(Normal, Turbo, Eco) - ";
    cin >> temp;
    ek.Execute("Turbo");
    delete[] name;
    return 0;
}

