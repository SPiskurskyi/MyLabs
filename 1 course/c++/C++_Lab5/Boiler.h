#include <iostream>
#include <string>
using namespace std;

class Boiler
{
private:
	bool isTurned;

public:
	virtual void On() 
	{ 
		isTurned = true;
		cout << "Electric kettle turned on\n";
	}
	virtual void Off() 
	{ 
		isTurned = false; 
		cout << "Electric kettle turned off\n";
	}
	virtual bool Status() 
	{ 
		return isTurned;
	}
	virtual void Execute(string mode) = 0;

};