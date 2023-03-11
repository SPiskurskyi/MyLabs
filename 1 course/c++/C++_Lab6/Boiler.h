#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

#ifndef Boiler
#define Boiler

class CBoiler 
{
protected:
	int m_thermalPower;
	bool m_isTurned;
public:
	CBoiler();
	CBoiler(int power);
	CBoiler(const CBoiler* obj);
	virtual ~CBoiler();
	void On();
	void Off();
	bool Status();
	virtual void ShowInfo() = 0;
	CBoiler& operator =(const CBoiler&);
};
#endif 