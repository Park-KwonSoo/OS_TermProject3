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
	//Safe�� Process���� �����ϴ� �ӽ� ����Ʈ
	int* isSafe = new int[this->need.size()];
	int isSafe_size = 0;
	bool canDo = true;

	//��� process�� sequnce�� ������ safe�ϴ�, �� size(bankers) = size(sequence)�� safe, �� ���� �����ϱ� ���� ����
	int numberOfBankers = this->bankers.size();

	Resource Temp;
	//Process�� �߿��� Need���� Allocation���� �ذ� �� �� �ִ� ���� ���� ã��, �� Available - need >= 0�ΰ͵�
	//�װ͵���  index���� isSafe ����Ʈ�� �����Ѵ�.
	for (int i = 0; i < this->need.size(); i++) {
		Temp = this->Available - this->need.at(i);
		if (Temp.isSafe()) {
			isSafe[isSafe_size] = i;
			isSafe_size++;
		}
	}

	//erase�� �� index�� ������ ��ĭ�� ���� ���� j
	int j = 0;
	for (int i = 0; i < isSafe_size; i++) {
		//Available -= Need
		this->Available = this->Available - this->need.at(isSafe[i]);
		//Allocation+= Need 
		this->bankers.at(isSafe[i]).setAllocation(this->bankers.at(isSafe[i]).getAllocation() + this->need.at(isSafe[i]));
		//sequence�� process �߰�
		this->sequence.push_back(this->bankers.at(isSafe[i]));
		//�۾� �Ϸ�� process�� bankers�� need���� ����
		this->bankers.erase(this->bankers.begin() + isSafe[i] - j);
		this->need.erase(this->need.begin() + isSafe[i] - j);
		//������ �� index���� �Ѱ��� ������Ƿ�
		j++;
	}




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
