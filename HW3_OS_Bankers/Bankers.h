#pragma once
#include<vector>
#include"Process.h"

//Banker's Algorithm
//Process를 받아 해당 프로세스들이  Safe한지 검사하고 Safe하다면 Sequence를 출력
class Bankers
{
private :
	vector<Process> bankers;
public :
	//기본 생성자
	Bankers();
};

