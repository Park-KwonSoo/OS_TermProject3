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
		//Safe�� Process���� �����ϴ� �ӽ� ����Ʈ
		int* isSafeInt = new int[this->need.size()];
		int isSafe_size = 0;

		//��� process�� sequnce�� ������ safe�ϴ�, �� size(bankers) = size(sequence)�� safe, �� ���� �����ϱ� ���� ����
		int numberOfBankers = this->bankers.size();

		Resource Temp;
		//Process�� �߿��� Need���� Allocation���� �ذ� �� �� �ִ� ���� ���� ã��, �� Available - need >= 0�ΰ͵�
		//�װ͵���  index���� isSafe ����Ʈ�� �����Ѵ�.
		for (int i = 0; i < this->need.size(); i++) {
			Temp = this->Available - this->need[i];
			if (Temp.isSafe()) {
				isSafeInt[isSafe_size] = i;
				isSafe_size++;
				canDo = true;
			}
		}

		//erase�� �� index�� ������ ��ĭ�� ���� ���� j
		int j = 0;
		for (int i = 0; i < isSafe_size; i++) {
			//Available -= Need
			this->Available = this->Available - this->need[(isSafeInt[i] - j)];
			//Allocation+= Need 
			this->bankers[isSafeInt[i]- j].setAllocation(this->bankers[isSafeInt[i] - j].getAllocation() + this->need[isSafeInt[i] - j]);
			//sequence�� process �߰�
			this->sequence.push_back(this->bankers[isSafeInt[i] - j]);
			//�ش� ���μ����� �۾��� �Ϸ�Ǿ����Ƿ� Available�� �� �� �߰�
			this->Available = this->Available + this->bankers[isSafeInt[i] - j].getMax();
			//�۾� �Ϸ�� process�� bankers�� need���� ����
			if (this->bankers.size() != 1) {
				this->bankers.erase(this->bankers.begin() + isSafeInt[i] - j);
				this->need.erase(this->need.begin() + isSafeInt[i] - j);
			}
			else {
				this->bankers.clear();
				this->need.clear();
			}
			//������ �� index���� �Ѱ��� ������Ƿ�
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
