#pragma once
#include "Resource.h"


//프로세스 클래스
class Process
{
private :
	//Resource값으로 현재 할당된 Allocation과
	//프로세스가 실행이 되기 위해 필요한 Max
	Resource Max;
	Resource Allocation;
public : 
	//기본 생성자
	Process();

	//max 리소스를 할당
	void setMax(float * resource);

	//allocation 리소스를 할당
	void setAllocation(float * resource);
};

