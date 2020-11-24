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
	//���Ͽ� ������ ���ο� Resource ��
	Resource getNew(this->n);
	for (int i = 0; i < this->n; i++) 
		getNew.addResource(this->resource[i] + Temp.resource[i]);

	return getNew;
}

Resource Resource::operator-(const Resource Temp)
{
	//���� ������ ���ο� Resource ��
	Resource getNew(this->n);
	for (int i = 0; i < this->n; i++)
		getNew.addResource(this->resource[i] - Temp.resource[i]);

	return getNew;
}

bool Resource::isSafe()
{
	//��� ���� ����� true ����, �ϳ��� ������ return false
	for (int i = 0; i < this->n; i++)
		if (this->resource[i] < 0)
			return false;
	
	return true;
}
