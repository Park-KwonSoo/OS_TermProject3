#pragma once
#include<vector>
#include"Process.h"

//Banker's Algorithm
//Process를 받아 해당 프로세스들이  Safe한지 검사하고 Safe하다면 Sequence를 출력
class Bankers
{
private :
	//Bankers에 저장된 Available 값이다
	Resource Available;

	//Process를 시행하기 위한 벡터
	//각 프로세스의 Need값을 저장 및 갱신한다
	vector<Process> bankers;
	vector<Resource> need;

	//Process가 safe한지 확인하는 safe
	//Sequeces는 safe하다면 Sequence를 출력한다.
	bool safe;
	vector<Process> sequence;
public :
	//기본 생성자
	Bankers();

	//프로세스를 bankers에 넣는다.
	//또한 need값을 계산하여 need에도 넣는다.
	void addProcess(Process process);

	//this->Available = Available
	void setAvailable(Resource Available);

	//safe한 프로세스를 sequence에 넣는다.
	void addSequence(Process process);

	//Bankers Algorithm을 수행하여 safe한지 계산한다
	void _BANKERS();

	//Bankers Algorithm을 수행하여 결과를 출력한다.
	void printBankers();
};

