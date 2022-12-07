#include "Boiler.h"
#ifndef ElectricBoiler
#define ElectricBoiler
class CElectricBoiler : virtual public CBoiler
{
protected:
	char* m_pszElectricName;
public:
	CElectricBoiler();
	CElectricBoiler(int power, char* electricname);
	CElectricBoiler(const CElectricBoiler& obj);
	virtual ~CElectricBoiler();
	virtual void ShowInfo();
	CElectricBoiler& operator =(CElectricBoiler&);
};
#endif