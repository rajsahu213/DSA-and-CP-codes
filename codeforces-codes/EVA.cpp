#include <bits/stdc++.h>
using namespace std;
int main() {
	cout << "**************************" << endl;
	cout << "  EARNED VALUE ANALYSIS" << endl;
	cout << "**************************" << endl;
	while (true) {
		cout << "Enter the value for Budgeted Cost for Work Scheduled\n";
		int BCWS; cin >> BCWS;
		cout << "Enter the value for Budgeted Cost for Work Performed\n";
		int BCWP; cin >> BCWP;
		cout << "Enter the value for Actual Cost for Work Performed\n";
		int ACWP; cin >> ACWP;
		cout << "Enter the value for Budget Estimated at Completion\n";
		int EAC; cin >> EAC;
		cout << "Enter the value for Budget at Completion\n";
		int BAC; cin >> BAC;
		cout << "\nHere you go !!\n\n";
		if (BCWS < 0 || BCWP < 0 || ACWP < 0 || EAC < 0 || BAC < 0) {
			cout << "Sorry!! the given inputs are invalid since the cost cannot be negative." << endl;
			continue;
		}
		if (BAC < BCWS) {
			cout << "Sorry!! the given inputs are invalid.The work for whole task cannot be less than the schedeuled." << endl;
			continue;
		}
		if (BCWP == 0 || ACWP == 0) {
			cout << "Sorry!! the given inputs are invalid.The work performed is 0 means the work is not started yet." << endl;
			continue;
		}
		if (BCWS == 0) {
			cout << "Sorry!! the given inputs are invalid.The work scheduled cost cannot be 0 for a project." << endl;
			continue;
		}
		if (BAC == 0 || EAC == 0) {
			cout << "Sorry!! the given inputs are invalid.The estimated or expected budget at completion cannot be 0." << endl;
			continue;
		}
		int CV = BCWP - ACWP;
		int SV = BCWP - BCWS;
		cout << "The cost variance for the project is => " << CV << "\n\n";
		cout << "In Percentage => " <<  round(((double)CV / BCWP) * 100.0) << "%"  << "\n\n";
		if (CV < 0) {
			cout << "Project is cost overrun\n\n";
		}
		else if (CV > 0) {
			cout << "Project is cost underrun\n\n";
		}
		else {
			cout << "Project is costing expectedly.\n\n";
		}
		cout << "The Scheduled variance for the project is => " << SV << "\n\n";
		cout << "In Percentage => " <<  round(((double)SV / BCWS) * 100.0) << "%" << "\n\n";
		if (SV < 0) {
			cout << "Project is behind schedule\n\n";
		}
		else if (SV > 0) {
			cout << "Project is ahead schedule\n\n";
		}
		else {
			cout << "Project is running expectedly.\n\n";
		}
		cout << "Cost Performance Index => " << BCWP / ACWP << "\n\n";
		cout << "Scheduled Performance Index => " << BCWP / BCWS << "\n\n";
		cout << "Variance at Completion => " << BAC - EAC << "\n\n";
		cout << endl;
		cout << "Do you want to perform once again?(Y/N): ";
		char x; cin >> x;
		if (x == 'N' || x == 'n')break;
	}
	cout << "THANK YOU" << endl;
	return 0;
}