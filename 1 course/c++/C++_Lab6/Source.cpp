#include "MixedBoiler.h"


int main()
{
	char* name1 = new char[20];
	strcpy(name1, "Ferroli");
	char* name2 = new char[20];
	strcpy(name2, "DNIPRO");
	CMixedBoiler b1(100,name1,name2);
	b1.On();
	b1.ShowInfo();
	CMixedBoiler b2 = b1;
	b2.Off();
	b2.ShowInfo();

}
