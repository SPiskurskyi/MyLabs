#include "MixedBoiler.h"


CMixedBoiler::CMixedBoiler() : CBoiler(), CGasBoiler(), CElectricBoiler()
{
	cout << "CMixedBoiler default constructor " << endl;
}
CMixedBoiler::CMixedBoiler(int power, char* gasname, char* electricname) : CBoiler(power), CGasBoiler(power, gasname), CElectricBoiler(power, electricname)
{
	cout << "CMixedBoiler constructor " << endl;
}
CMixedBoiler::CMixedBoiler(const CMixedBoiler& obj) : CBoiler(obj), CGasBoiler(obj), CElectricBoiler(obj)
{
	cout << "CMixedBoiler copy constructor" << endl;
}
CMixedBoiler::~CMixedBoiler()
{
	cout << "CMixedBoiler destructor " << endl;
}
void CMixedBoiler::ShowInfo() 
{
	cout << "\nName of Mixed Boiler - " << m_pszElectricName << '-' << m_pszGasName << endl;
	cout << "Thermal Power - " << m_thermalPower << " kW " << endl;
	if (Status() == true)
	{
		cout << "Mixed Boiler turned on " << endl << endl;
	}
	else
	{
		cout << "Mixed Boiler turned off " << endl << endl;
	}
}
CMixedBoiler& CMixedBoiler::operator=(CMixedBoiler& obj)
{
	if (this != &obj)
	{
		cout << "CAutoMotoRacer operator=" << endl;
		CElectricBoiler::operator=(obj);
		CGasBoiler::operator=(obj);
	}
	return *this;
}