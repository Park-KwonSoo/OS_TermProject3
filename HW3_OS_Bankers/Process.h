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
public : 
	//�⺻ ������
	Process();

	//max ���ҽ��� �Ҵ�
	void setMax(float * resource);

	//allocation ���ҽ��� �Ҵ�
	void setAllocation(float * resource);
};

