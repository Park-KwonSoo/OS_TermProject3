#pragma once
#include "Resource.h"


//���μ��� Ŭ����
class Process
{
private :
	//Resource������ ���� �Ҵ�� Allocation��
	//���μ����� ������ �Ǳ� ���� �ʿ��� Max
	Resource Max;
	Resource Allocation;

	//���� �Ҵ� �ϱ� ���� n��
	int n;
public : 
	//�⺻ ������
	Process();

	//this->n set
	void setN(int n);

	//max ���ҽ��� �Ҵ�
	void setMax(float * resource);

	//allocation ���ҽ��� �Ҵ�
	void setAllocation(float * resource);

	//return this->Max
	Resource getMax();

	//return this->Allocation
	Resource getAllocation();
};

