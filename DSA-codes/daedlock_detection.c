#include<stdio.h>
#define MAX 20
int M, N;
int LessThan(int Array1[], int Array2[]) {
	int i, j;
	for (i = 0; i < M; i++) {
		if (Array1[i] > Array2[i]) {
			return 0;
		}
	}
	return 1;
}
int DeadlockDetectionAlgorithm(int Request[MAX][MAX], int Allocation[MAX][MAX], int Available[MAX]) {
	int i, j, Work[MAX], Finish[MAX];
	for (i = 0; i < N; i++) {
		Finish[i] = 0;
	}
	for (i = 0; i < M; i++) {
		Work[i] = Available[i];
	}
	int flag = 0;
	while (1) {
		flag = 0;
		for (i = 0; i < N; i++) {
			if (LessThan(Request[i], Work) && Finish[i] == 0) {
				printf("Order: %d\n", i);
				flag = 1;
				for (j = 0; j < M; j++) {
					Work[j] = Work[j] + Allocation[i][j];
				}
				Finish[i] = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
	for (i = 0; i < N; i++) {
		if (Finish[i] == 0) {
			printf("System is in a deadlocked state\n");
			printf("%d th process is deadlocked\n", i);
			//cout << "System is in a deadlocked state\n" << i << "th process is deadlocked\n";
			return 0;
		}
	}
	cout << "System is not in a deadlocked state\n";
	return 1;
}
int main()
{
	int i, j, Allocation[MAX][MAX], Available[MAX], Request[MAX][MAX], pid;
	printf("Enter the no of processes and no of types of resources respectively\n");
	scanf("%d %d", &N, &M);
	printf("Enter Allocated resources of each type process by process\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &Allocation[i][j]);
		}
	}
	printf("Enter requested resources of each type process by process\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &Request[i][j]);
		}
	}
	printf("Enter available resources of each type\n");
	for (j = 0; j < M; j++) {
		scanf("%d", &Available[j]);
	}
	DeadlockDetectionAlgorithm(Request, Allocation, Available);
	return 0;
}