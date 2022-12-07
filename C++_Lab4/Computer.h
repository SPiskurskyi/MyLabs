#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Computer
{
private:
	string CPU_model;
	double CPU_frequency;
	int HDD_size;
	int RAM_size;
	string GPU_model;
	bool Operating_time;
	int Count_of_programs;
	static int Count_of_computers;
public:
	Computer(string cpu_model, double cpu_frequency, int hdd_size, int ram_size, string gpu_model, bool operating_time, int count_of_programs);
	Computer();
	~Computer();
	Computer& operator=(const Computer& other);
	Computer(const Computer& other);
	////////////////////////////////////////////////////
	void SetCPU(string cpu_model, double cpu_frequency);
	void SetRAM(int ram_size);
	void SetHDD(int hdd_size);
	void SetGPU(string gpu_model);
	void SetOperating_time(bool operating_time);
	void SetCount_of_programs(int count_of_programs);
	////////////////////////////////////////////////////
	string GetCPU_model();
	double GetCPU_frequency();
	int GetRAM();
	int GetHDD();
	string GetGPU();
	int GetÎperating_time();
	int GetCount_of_programs();
	int GetCount_ofComputers();
	////////////////////////////////////////////////////
	void ShowCPU();
	void ShowRAM();
	void ShowHDD();
	void ShowGPU();
	void ShowOperating_time();
	void ShowCount_of_programs();
	void ShowCount_of_computers();
	void ShowInfo();
	////////////////////////////////////////////////////
	double RunPrograms(const Computer& other, int operations_per_program);
	Computer& AddPrograms(Computer& other, int count);	
	Computer& RemovePrograms(Computer& other, int count);
	////////////////////////////////////////////////////
	friend ostream& operator<< (ostream& output, const Computer& comp);
	friend std::istream& operator>> (istream& in, Computer& comp);
	////////////////////////////////////////////////////
	Computer operator*(const Computer& comp);
	Computer operator*(int value);
	////////////////////////////////////////////////////
	Computer& operator++();
	Computer& operator++(int);
	////////////////////////////////////////////////////
	bool operator==(const Computer& comp);
	bool operator||(const Computer& comp);
};
