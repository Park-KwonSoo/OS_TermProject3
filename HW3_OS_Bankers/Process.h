#pragma once
#include "Resource.h"
#include<string>


//���μ��� Ŭ����
class Process
{
private :
	//���μ����� �̸�
	string processName;

	//Resource������ ���� �Ҵ�� Allocation��
	//���μ����� ������ �Ǳ� ���� �ʿ��� Max
	Resource Max;
	Resource Allocation;

	//���� �Ҵ� �ϱ� ���� n��
	int n;
public : 
	//�⺻ ������
	Process();

	//�⺻������ : ���μ��� �̸��� �����Ѵ�.
	Process(string processName);

	//this->n set
	void setN(int n);

	//max ���ҽ��� �Ҵ�
	void setMax(Resource Max);

	//allocation ���ҽ��� �Ҵ�
	void setAllocation(Resource Allocation);

	//return this->Max
	Resource getMax();

	//return this->Allocation
	Resource getAllocation();

	//���μ����� �̸��� ����Ѵ�.
	void printProcess();
};

