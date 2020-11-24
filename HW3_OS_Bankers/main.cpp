#include "Bankers.h"

int main() {
	Resource R0_M(4), R1_M(4), R2_M(4), R3_M(4), R4_M(4);
	Resource R0_A(4), R1_A(4), R2_A(4), R3_A(4), R4_A(4);
	Resource available(4);

	R0_M.addResource(6); R0_M.addResource(0); R0_M.addResource(1); R0_M.addResource(2);
	R1_M.addResource(1); R1_M.addResource(7); R1_M.addResource(5); R1_M.addResource(0);
	R2_M.addResource(2); R2_M.addResource(3); R2_M.addResource(5); R2_M.addResource(6);
	R3_M.addResource(1); R3_M.addResource(6); R3_M.addResource(5); R3_M.addResource(3);
	R4_M.addResource(1); R4_M.addResource(6); R4_M.addResource(5); R4_M.addResource(6);

	R0_A.addResource(4); R0_A.addResource(0); R0_A.addResource(0); R0_A.addResource(1);
	R1_A.addResource(1); R1_A.addResource(1); R1_A.addResource(0); R1_A.addResource(0);
	R2_A.addResource(1); R2_A.addResource(2); R2_A.addResource(5); R2_A.addResource(4);
	R3_A.addResource(0); R3_A.addResource(6); R3_A.addResource(3); R3_A.addResource(3);
	R4_A.addResource(0); R4_A.addResource(2); R4_A.addResource(1); R4_A.addResource(2);

	available.addResource(3); available.addResource(2); available.addResource(1); available.addResource(1);

	Process P0("P0"), P1("P1"), P2("P2"), P3("P3"), P4("P4");
	
	P0.setMax(R0_M);
	P0.setAllocation(R0_A);

	P1.setMax(R1_M);
	P1.setAllocation(R1_A);

	P2.setMax(R2_M);
	P2.setAllocation(R2_A);

	P3.setMax(R3_M);
	P3.setAllocation(R3_A);

	P4.setMax(R4_M);
	P4.setAllocation(R4_A);
	
	Bankers Bak;
	Bak.addProcess(P0);
	Bak.addProcess(P1);
	Bak.addProcess(P2);
	Bak.addProcess(P3);
	Bak.addProcess(P4);
	
	Bak.setAvailable(available);

	Bak._BANKERS();
	cout << "Resource가 문제에 나와 있는 대로 주어졌을 때 결과 : " << endl;
	Bak.printBankers();

	cout << endl;
	//P4가 (1, 2, 0, 0)만큼 Granted 되었을 때 결과
	Resource R4_G(4);
	R4_G.addResource(1 + 1); R4_G.addResource(6 + 2); R4_G.addResource(5); R4_G.addResource(6);

	Process P4_Granted("P4 : granted");
	P4_Granted.setMax(R4_G);
	P4_Granted.setAllocation(R4_A);

	Bankers afterGrant;
	afterGrant.addProcess(P0);
	afterGrant.addProcess(P1);
	afterGrant.addProcess(P2);
	afterGrant.addProcess(P3);
	afterGrant.addProcess(P4_Granted);

	afterGrant.setAvailable(available);
	
	afterGrant._BANKERS();
	cout << "P4가 Grant 된 이후의 결과 : " << endl;
	afterGrant.printBankers();


}