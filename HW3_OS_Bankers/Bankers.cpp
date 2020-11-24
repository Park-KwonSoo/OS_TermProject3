#include "Bankers.h"

Bankers::Bankers()
{
	this->safe = false;
}

void Bankers::addProcess(Process process)
{
	this->bankers.push_back(process);
	this->need.push_back(process.getMax() - process.getAllocation());
}

void Bankers::setAvailable(Resource Available)
{
	this->Available = Available;
}

void Bankers::addSequence(Process process)
{
	this->sequence.push_back(process);
}

void Bankers::_BANKERS()
{
	bool canDo = true;

	while (canDo) {
		canDo = false;
		//Safe한 Process들을 저장하는 임시 리스트
		int* isSafeInt = new int[this->need.size()];
		int isSafe_size = 0;

		//모든 process가 sequnce에 들어오면 safe하다, 즉 size(bankers) = size(sequence)면 safe, 그 값을 저장하기 위한 변수
		int numberOfBankers = this->bankers.size();

		Resource Temp;
		//Process들 중에서 Need값이 Allocation에서 해결 할 수 있는 것을 전부 찾음, 즉 Available - need >= 0인것들
		//그것들의  index값을 isSafe 리스트에 저장한다.
		for (int i = 0; i < this->need.size(); i++) {
			Temp = this->Available - this->need[i];
			if (Temp.isSafe()) {
				isSafeInt[isSafe_size] = i;
				isSafe_size++;
				canDo = true;
			}
		}

		//erase할 때 index를 앞으로 한칸씩 당기기 위한 j
		int j = 0;
		for (int i = 0; i < isSafe_size; i++) {
			//Available -= Need
			this->Available = this->Available - this->need[(isSafeInt[i] - j)];
			//Allocation+= Need 
			this->bankers[isSafeInt[i]- j].setAllocation(this->bankers[isSafeInt[i] - j].getAllocation() + this->need[isSafeInt[i] - j]);
			//sequence에 process 추가
			this->sequence.push_back(this->bankers[isSafeInt[i] - j]);
			//해당 프로세스의 작업이 완료되었으므로 Available에 그 값 추가
			this->Available = this->Available + this->bankers[isSafeInt[i] - j].getMax();
			//작업 완료된 process는 bankers와 need에서 삭제
			if (this->bankers.size() != 1) {
				this->bankers.erase(this->bankers.begin() + isSafeInt[i] - j);
				this->need.erase(this->need.begin() + isSafeInt[i] - j);
			}
			else {
				this->bankers.clear();
				this->need.clear();
			}
			//삭제한 후 index값이 한개씩 당겨지므로
			j++;
		}

		delete[] isSafeInt;
	}

	if (this->bankers.empty())
		this->safe = true;
	else
		this->safe = false;
}

void Bankers::printBankers()
{
	if (this->safe) {
		cout << "It's Safe :  <";
		for (int i = 0; i < this->sequence.size(); i++) {
			this->sequence.at(i).printProcess();
			cout << ", ";
		}
		cout << ">" << endl;
	}
	else
		cout << "It's Not Safe" << endl;
}
