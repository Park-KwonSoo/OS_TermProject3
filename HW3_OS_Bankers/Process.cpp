#include "Process.h"

Process::Process()
{
	this->n = 0;
}

void Process::setN(int n)
{
	this->n = n;
}

void Process::setMax(float* resource)
{
	for (int i = 0; i < this->n; i++)
		this->Max.addResource(resource[i]);
}

void Process::setAllocation(float* resource)
{
	for (int i = 0; i < this->n; i++)
		this->Allocation.addResource(resource[i]);
}

Resource Process::getMax()
{
	return this->Max;
}

Resource Process::getAllocation()
{
	return this->Allocation;
}
