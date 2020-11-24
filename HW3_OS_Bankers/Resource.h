#pragma once
#include<iostream>
using namespace std;

//���μ����� �ʿ��� �ڿ��� ���� �����ϴ� Ŭ����
class Resource
{
private : 
	//�ڿ��� ������ ���� �Ҵ� �޾� �� ���� �����Ѵ�.
	float* resource;
	//���� �ڿ��� ������ count�Ѵ�.
	int count;
public :
	//�ڿ� �⺻ ������
	Resource();

	//�ڿ� ������ : Parameter : n = n�� ũ��� �����Ҵ� �Ѵ�
	Resource(int n);

	//�ڿ��� resource�� add�Ѵ�
	void addResource(float resource);

	//�����Ҵ� �� ������ �����Ѵ�.
	int getN();

	//this + Temp = ��� Resource�� ��
	Resource operator+ (const Resource Temp);

	//this - Temp =  ��� Resource�� ��
	Resource operator- (const Resource Temp);

	//this Resource�� ��� ���� ����� ����
	bool isSafe();
};
