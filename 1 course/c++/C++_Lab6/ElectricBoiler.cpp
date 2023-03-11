#include "ElectricBoiler.h"

CElectricBoiler::CElectricBoiler() : CBoiler()
{
	cout << "CElectricBoiler default constructor " << endl;
	m_pszElectricName = new char[20];
	strcpy(m_pszElectricName, "No name");
}
CElectricBoiler::CElectricBoiler(int power, char* electricname) : CBoiler(power)
{
	cout << "CElectricBoiler constructor " << endl;
	m_pszElectricName = new char[strlen(electricname) + 1];
	strcpy(m_pszElectricName, electricname);
}
CElectricBoiler::CElectricBoiler(const CElectricBoiler& obj) : CBoiler(obj)
{
	cout << "CElectricBoiler copy constructor" << endl;
	m_pszElectricName = new char[strlen(obj.m_pszElectricName) + 1];
	strcpy(m_pszElectricName, obj.m_pszElectricName);
}
CElectricBoiler::~CElectricBoiler()
{
	cout << "CElectricBoiler destructor " << endl;
	delete[] m_pszElectricName;
}

void CElectricBoiler::ShowInfo()
{
	cout << "\nName of Electric Boiler - " << m_pszElectricName << endl;
	cout << "Thermal Power - " << m_thermalPower << " kW " << endl;
	if (Status() == true)
	{
		cout << "Electric Boiler turned on " << endl << endl;
	}
	else
	{
		cout << "Electric Boiler turned off " << endl << endl;
	}
}

CElectricBoiler& CElectricBoiler::operator=(CElectricBoiler& obj)
{
	if (this != &obj)
	{
		cout << "CElectricBoiler operator=" << endl;
		delete[] m_pszElectricName;
		m_pszElectricName = new char[strlen(obj.m_pszElectricName) + 1];
		strcpy(m_pszElectricName, obj.m_pszElectricName);
		CBoiler::operator=(obj);
	}
	return *this;
}