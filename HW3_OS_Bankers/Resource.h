#pragma once
#include<iostream>
using namespace std;

//프로세스에 필요한 자원의 값을 저장하는 클래스
class Resource
{
private : 
	//자원의 개수를 동적 할당 받아 그 값에 저장한다.
	float* resource;
	//현재 자원의 개수를 count한다.
	int count;
	//현재 동적할당 된 자원의 개수를 저장한다.
	int n;
public :
	//자원 기본 생성자
	Resource();

	//자원 생성자 : Parameter : n = n의 크기로 동적할당 한다
	Resource(int n);

	//해당 자원의 개수를 동적할당한다.
	void setN(int n);

	//자원에 resource를 add한다
	void addResource(float resource);

	//동적할당 된 개수를 리턴한다.
	int getN();

	//this + Temp = 모든 Resource의 합
	Resource operator+ (const Resource Temp);

	//this - Temp =  모든 Resource의 차
	Resource operator- (const Resource Temp);

	//this Resource의 모든 값이 양수면 리턴
	bool isSafe();
};

