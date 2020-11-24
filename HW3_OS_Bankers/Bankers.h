#pragma once
#include<vector>
#include"Process.h"

//Banker's Algorithm
//Process�� �޾� �ش� ���μ�������  Safe���� �˻��ϰ� Safe�ϴٸ� Sequence�� ���
class Bankers
{
private :
	//Bankers�� ����� Available ���̴�
	Resource Available;

	//Process�� �����ϱ� ���� ����
	//�� ���μ����� Need���� ���� �� �����Ѵ�
	vector<Process> bankers;
	vector<Resource> need;

	//Process�� safe���� Ȯ���ϴ� safe
	//Sequeces�� safe�ϴٸ� Sequence�� ����Ѵ�.
	bool safe;
	vector<Process> sequence;
public :
	//�⺻ ������
	Bankers();

	//���μ����� bankers�� �ִ´�.
	//���� need���� ����Ͽ� need���� �ִ´�.
	void addProcess(Process process);

	//this->Available = Available
	void setAvailable(Resource Available);

	//safe�� ���μ����� sequence�� �ִ´�.
	void addSequence(Process process);

	//Bankers Algorithm�� �����Ͽ� safe���� ����Ѵ�
	void _BANKERS();

	//Bankers Algorithm�� �����Ͽ� ����� ����Ѵ�.
	void printBankers();
};

