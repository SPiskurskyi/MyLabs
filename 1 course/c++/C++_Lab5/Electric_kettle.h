#include "Boiler.h"

class Electric_kettle : public Boiler
{
private:
	char* name;
	int volume;
public:
	Electric_kettle(char* name, int volume);
	virtual ~Electric_kettle();
	void Execute(string mode) override;
	void SetVolume(int volume);
	int  GetVolume();
	char* Getname();
};