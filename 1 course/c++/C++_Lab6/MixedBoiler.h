#include "GasBoiler.h"
#include "ElectricBoiler.h"
#ifndef MixedBoiler
#define MixedBoiler


class CMixedBoiler : public CElectricBoiler, CGasBoiler
{
public:
	CMixedBoiler();
	CMixedBoiler(int power , char* gasname,char* electricname);
	CMixedBoiler(const CMixedBoiler& obj);
	virtual ~CMixedBoiler();
	virtual void ShowInfo();
	CMixedBoiler& operator =(CMixedBoiler&);
};
#endif