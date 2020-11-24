#include "Process.h"

Process::Process()
{
	this->n = 0;
	this->processName = "";
}

Process::Process(string processName)
{
	this->processName = processName;
}

void Process::setN(int n)
{
	this->n = n;
}

void Process::setMax(Resource Max)
{
	this->Max = Max;
}

void Process::setAllocation(Resource Allocation)
{
	this->Allocation = Allocation;
}

Resource Process::getMax()
{
	return this->Max;
}

Resource Process::getAllocation()
{
	return this->Allocation;
}

void Process::printProcess()
{
	cout << this->processName << ", ";
}
