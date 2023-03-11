#include "Boiler.h"
#ifndef GasBoiler
#define GasBoiler

class CGasBoiler : virtual public CBoiler
{
protected:
	char* m_pszGasName;
public:
	CGasBoiler();
	CGasBoiler(int power ,char* gasname);
	CGasBoiler(const CGasBoiler& obj);
	virtual ~CGasBoiler();
	virtual void ShowInfo();
	CGasBoiler& operator =(CGasBoiler&);
};
#endif