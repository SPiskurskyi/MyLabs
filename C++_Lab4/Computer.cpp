#include "Computer.h"

int Computer::Count_of_computers = 0;
////////////////////////////////////////////////////
Computer::Computer(string cpu_model, double cpu_frequency, int hdd_size, int ram_size, string gpu_model, bool operating_time, int count_of_programs)
{
	CPU_model = cpu_model;
	CPU_frequency = cpu_frequency;
	HDD_size = hdd_size;
	RAM_size = ram_size;
	GPU_model = gpu_model;
	Operating_time = operating_time;
	Count_of_programs = count_of_programs;
	Count_of_computers++;
	cout << "\nComputer was created! - " << this << endl;
}
Computer::Computer()
{
	CPU_model = "None";
	CPU_frequency = 0;
	HDD_size = 0;
	RAM_size = 0;
	GPU_model = "None";
	Operating_time = 0;
	Count_of_programs = 0;
	Count_of_computers++;
	cout << "\nComputer was created! - " << this << endl;
}
Computer::~Computer()
{
	Count_of_computers--;
	cout << "\n\nComputer was destroyed! - " << this << endl;
}
Computer & Computer::operator=(const Computer& other)
{
	if (this == &other)
	{
		return *this;
	}
	CPU_model = other.CPU_model;
	CPU_frequency = other.CPU_frequency;
	HDD_size = other.HDD_size;
	RAM_size = other.RAM_size;
	GPU_model = other.GPU_model;
	Operating_time = other.Operating_time;
	Count_of_programs = other.Count_of_programs;
	cout << "\nOperator \"=\"  - " << this << endl;
	return *this;
}
Computer::Computer(const Computer& other)
{
	
	CPU_model = other.CPU_model;
	CPU_frequency = other.CPU_frequency;
	HDD_size = other.HDD_size;
	RAM_size = other.RAM_size;
	GPU_model = other.GPU_model;
	Operating_time = other.Operating_time;
	Count_of_programs = other.Count_of_programs;
	cout << "\nCopy Constructor  - " << this << endl;
	Count_of_computers++;
}
////////////////////////////////////////////////////
void Computer::SetCPU(string cpu_model, double cpu_frequency)
{
	CPU_model = cpu_model;
	CPU_frequency = cpu_frequency;
}
void Computer::SetRAM(int ram_size)
{
	RAM_size = ram_size;
}
void Computer::SetHDD(int hdd_size)
{
	HDD_size = hdd_size;
}
void Computer::SetGPU(string gpu_model)
{
	GPU_model = gpu_model;
}
void Computer::SetOperating_time(bool operating_time)
{
	Operating_time = operating_time;
}
void Computer::SetCount_of_programs(int count_of_programs)
{
	Count_of_programs = count_of_programs;
}
////////////////////////////////////////////////////
string Computer::GetCPU_model()
{
	return CPU_model;
}
double Computer::GetCPU_frequency()
{
	return CPU_frequency;
}
int Computer::GetRAM()
{
	return RAM_size;
}
int Computer::GetHDD()
{
	return HDD_size;
}
string Computer::GetGPU()
{
	return GPU_model;
}
int Computer::GetÎperating_time()
{
	return Operating_time;
}
int Computer::GetCount_of_programs()
{
	return Count_of_programs;
}
int Computer::GetCount_ofComputers() 
{
	return Count_of_computers;
}
////////////////////////////////////////////////////
void Computer::ShowCPU()
{
	cout << "\nCPU model - " << this->CPU_model;
	cout << "\nCPU frequency - " << this->CPU_frequency << "GHz";
}
void Computer::ShowRAM()
{
	cout << "\nRAM size - " << this->RAM_size << "GB";
}
void Computer::ShowHDD()
{
	cout<< "\nHDD size - " << this->HDD_size << "GB";
}
void Computer::ShowGPU()
{
	cout << "\nGPU model - " << this->GPU_model;
}
void Computer::ShowOperating_time()
{
	cout << "\nOprating time computer(1 or 0) - " << this->Operating_time;
}
void Computer::ShowCount_of_programs()
{
	cout << "\nCount of programs on computer - " << this->Count_of_programs;
}
void Computer::ShowCount_of_computers()
{
	cout << "\nCount of computers - " << Count_of_computers;
}
void Computer::ShowInfo() 
{
	cout << "\nCPU model - " << this->CPU_model;
	cout << "\nCPU frequency - " << this->CPU_frequency << "GHz";
	cout << "\nRAM size - " << this->RAM_size << "GB";
	cout << "\nHDD size - " << this->HDD_size << "GB";
	cout << "\nGPU model - " << this->GPU_model;
	cout << "\nOprating time computer - " << this->Operating_time;
	cout << "\nCount of programms on computer - " << this->Count_of_programs;
	cout << "\nCount of computers - " << Count_of_computers << endl;
}
////////////////////////////////////////////////////
double Computer::RunPrograms(const Computer& other, int operations_per_program)
{
	double time = 0;
	time = (Count_of_programs * operations_per_program) / (CPU_frequency * pow(10, 7));
	return time;
}
Computer& Computer::AddPrograms(Computer& other, int count)
{
	Count_of_programs += count;
	return *this;
}
Computer& Computer::RemovePrograms(Computer& other, int count)
{
	Count_of_programs -= count;
	return *this;
}
////////////////////////////////////////////////////
ostream& operator<< (ostream& output, const Computer& comp)
{
	output << "\nCPU model - " << comp.CPU_model;
	output << "\nCPU frequency - " << comp.CPU_frequency << "GHz";
	output << "\nRAM size - " << comp.RAM_size << "GB";
	output << "\nHDD size - " << comp.HDD_size << "GB";
	output << "\nGPU model - " << comp.GPU_model;
	output << "\nOprating time computer - " << comp.Operating_time;
	output << "\nCount of programms on computer - " << comp.Count_of_programs;
	output << "\nCount of computers - " << comp.Count_of_computers << endl;
	return output;
}
istream& operator>> (istream& in, Computer& comp)
{
	cout << "\nEnter CPU model - ";
	getline(in, comp.CPU_model);
	cout << "\nEnter CPU frequency(GHz) - ";
	in >> comp.CPU_frequency;
	cout << "\nEnter HDD size(GB) - ";
	in >> comp.HDD_size;
	cout << "\nEnter RAM size(GB) - ";
	in >> comp.RAM_size;
	cout << "\nEnter GPU model - ";
	in.get();
	getline(in, comp.GPU_model);
	cout << "\nEnter Operating time(1 or 0) - ";
	in >> comp.Operating_time;
	cout << "\nEnter Count of programms - ";
	in >> comp.Count_of_programs;
	return in;
}
////////////////////////////////////////////////////
Computer Computer::operator*(const Computer& comp)
{
	Computer temp;
	temp.CPU_model = this->CPU_model;
	temp.CPU_frequency = this->CPU_frequency;
	temp.HDD_size = this->HDD_size;
	temp.RAM_size = this->RAM_size;
	temp.GPU_model = this->GPU_model;
	temp.Operating_time = this->Operating_time;
	temp.Count_of_programs = comp.Count_of_programs * this->Count_of_programs;
	return temp;
}
Computer Computer::operator*(int value)
{
	Computer temp;
	temp.CPU_model = this->CPU_model;
	temp.CPU_frequency = this->CPU_frequency;
	temp.HDD_size = this->HDD_size;
	temp.RAM_size = this->RAM_size;
	temp.GPU_model = this->GPU_model;
	temp.Operating_time = this->Operating_time;
	temp.Count_of_programs = this->Count_of_programs * value;
	return temp;
}
////////////////////////////////////////////////////
Computer & Computer::operator++()
{
	this->Count_of_programs++;
	return *this;
}
Computer& Computer::operator++(int)
{
	Computer temp = *this;
	this->Count_of_programs++;
	return temp;
}
////////////////////////////////////////////////////
bool Computer::operator==(const Computer& comp)
{
	if (this->CPU_model == comp.CPU_model && this->CPU_frequency == comp.CPU_frequency && this->RAM_size == comp.RAM_size && this->HDD_size == comp.HDD_size && this->GPU_model == comp.GPU_model && this->Operating_time == comp.Operating_time)
	{
		return true;
	}
	else return false;
}
bool Computer::operator||(const Computer& comp)
{
	if (this->Operating_time || comp.Operating_time)
	{
		return true;
	}
	else return false;
}