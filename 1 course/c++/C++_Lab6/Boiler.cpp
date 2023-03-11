#include "Boiler.h"

CBoiler::CBoiler() : m_thermalPower(0), m_isTurned(false)
{
	cout << "CBoiler default constructor " << endl;
}
CBoiler::CBoiler(int power) : m_isTurned(false)
{
	cout << "CBoiler constructor " << endl;
	m_thermalPower = power;

}
CBoiler::CBoiler(const CBoiler* obj) : m_isTurned(false)
{
	cout << "CBoiler copy constructor" << endl;
	this->m_thermalPower = obj->m_thermalPower;
}
CBoiler::~CBoiler()
{
	cout << "CBoiler destructor " << endl;
}
void CBoiler::On()
{
	m_isTurned = true;
	cout << "Boiler turned on\n";
}
void CBoiler::Off()
{
	m_isTurned = false;
	cout << "Boiler turned off\n";
}
bool CBoiler::Status()
{
	return m_isTurned;
}
CBoiler& CBoiler::operator=(const CBoiler& obj)
{
	if (this != &obj)
	{
		cout << "CBoiler operator = " << endl;
		this->m_thermalPower = obj.m_thermalPower;
	}
	return *this;
}