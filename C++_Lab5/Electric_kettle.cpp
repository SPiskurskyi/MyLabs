#define _CRT_SECURE_NO_WARNINGS
#include "Electric_kettle.h"

Electric_kettle::Electric_kettle(char* name, int volume)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->volume = volume;
}
Electric_kettle:: ~Electric_kettle() 
{
	if (this->name!=0)
	{
		delete[] this->name;
	}
}
void Electric_kettle::Execute(string mode)
{
	if (Status() == 0)
	{
		cout << "Please turn on Electric kettle" << endl;
	}
	else if(Status() == 1)
	{
		if (mode == "Normal")
		{
			cout << "Normal mode - the water boils for 90 seconds\n";
		}
		else if (mode == "Turbo")
		{
			cout << "Turbo mode - the water boils for 30 seconds\n";
		}
		else if (mode == "Eco")
		{
			cout << "Eco mode - the water boils for 180 seconds\n";
		}
	}
}
void Electric_kettle::SetVolume(int volume)
	{
		this->volume = volume;
	}
int Electric_kettle::GetVolume() 
	{
		return this->volume;
	}
char* Electric_kettle::Getname()
{
	return name;
}