#include "Resource.h"

Resource::Resource()
{
	this->resource = new float;
	this->count = 0;
	this->n = 0;
}

Resource::Resource(int n)
{
	this->resource = new float(n);
	this->count = 0;
	this->n = n
}

void Resource::setList(int n)
{
	delete this->resource;
	this->resource = new float(n);
	this->n = n;
}

void Resource::addResource(float resource)
{
	if (this->count < n) {
		this->resource[this->count] = resource;
		this->count++;
	}
}

int Resource::getN()
{
	return this->n;
}

Resource Resource::operator+(const Resource Temp)
{
	//더하여 리턴할 새로운 Resource 값
	Resource getNew(this->n);
	for (int i = 0; i < this->n; i++) 
		getNew.addResource(this->resource[i] + Temp.resource[i]);

	return getNew;
}

Resource Resource::operator-(const Resource Temp)
{
	//빼서 리턴할 새로운 Resource 값
	Resource getNew(this->n);
	for (int i = 0; i < this->n; i++)
		getNew.addResource(this->resource[i] - Temp.resource[i]);

	return getNew;
}

bool Resource::isSafe()
{
	//모든 값이 양수면 true 리턴, 하나라도 음수면 return false
	for (int i = 0; i < this->n; i++)
		if (this->resource[i] < 0)
			return false;
	
	return true;
}
