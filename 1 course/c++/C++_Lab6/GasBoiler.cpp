#include "GasBoiler.h"

CGasBoiler::CGasBoiler() : CBoiler()
{
	cout << "CGasBoiler default constructor " << endl;
	m_pszGasName = new char[20];
	strcpy(m_pszGasName, "No name");
}
CGasBoiler::CGasBoiler(int power, char* gasname) : CBoiler(power)
{
	cout << "CGasBoiler constructor " << endl;
	m_pszGasName = new char[strlen(gasname) + 1];
	strcpy(m_pszGasName, gasname);
}
CGasBoiler::CGasBoiler(const CGasBoiler& obj) : CBoiler(obj)
{
	cout << "CGasBoiler copy constructor" << endl;
	m_pszGasName = new char[strlen(obj.m_pszGasName) + 1];
	strcpy(m_pszGasName, obj.m_pszGasName);
}
CGasBoiler::~CGasBoiler()
{
	cout << "CGasBoiler destructor " << endl;
	delete[] m_pszGasName;
}

void CGasBoiler::ShowInfo()
{
	cout << "\nName of Gas Boiler - " << m_pszGasName << endl;
	cout << "Thermal Power - " << m_thermalPower << " kW " << endl;
	if (Status() == true)
	{
		cout << "Gas Boiler turned on " << endl << endl;
	}
	else
	{
		cout << "Gas Boiler turned off " << endl <<endl;
	}
}

CGasBoiler& CGasBoiler::operator=(CGasBoiler& obj)
{
	if (this != &obj)
	{
		cout << "CGasBoiler operator=" << endl;
		delete[] m_pszGasName;
		m_pszGasName = new char[strlen(obj.m_pszGasName) + 1];
		strcpy(m_pszGasName, obj.m_pszGasName);
		CBoiler::operator=(obj);
	}
	return *this;
}