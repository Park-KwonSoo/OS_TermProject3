#pragma once
#include "Resource.h"
#include<string>


//프로세스 클래스
class Process
{
private :
	//프로세스의 이름
	string processName;

	//Resource값으로 현재 할당된 Allocation과
	//프로세스가 실행이 되기 위해 필요한 Max
	Resource Max;
	Resource Allocation;

	//동적 할당 하기 위한 n개
	int n;
public : 
	//기본 생성자
	Process();

	//기본생성자 : 프로세스 이름을 설정한다.
	Process(string processName);

	//this->n set
	void setN(int n);

	//max 리소스를 할당
	void setMax(Resource Max);

	//allocation 리소스를 할당
	void setAllocation(Resource Allocation);

	//return this->Max
	Resource getMax();

	//return this->Allocation
	Resource getAllocation();

	//프로세스의 이름을 출력한다.
	void printProcess();
};

