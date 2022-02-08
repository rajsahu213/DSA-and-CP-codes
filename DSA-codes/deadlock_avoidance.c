#include<stdio.h>
#define MAX 20
int M, N;
int LessThan(int Array1[], int Array2[]) {
	int i, j;
	for (i = 0; i < M; i++) {
		if (Array1[i] > Array2[i])
			return 0;
	}
	return 1;
}
int SafetyAlgorithm(int Need[MAX][MAX], int Allocation[MAX][MAX], int Available[MAX]) {
	int i, j;
	int Work[MAX];
	int Finish[MAX];
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
			if (LessThan(Need[i], Work) && Finish[i] == 0) {
				printf("Order: %d\n", i);
				flag = 1;
				for (j = 0; j < M; j++) {
					Work[j] = Work[j] + Allocation[i][j];
				}
				Finish[i] = 1;
			}
		}
		if (flag == 0)
			break;
	}
	for (i = 0; i < N; i++) {
		if (Finish[i] == 0) {
			return 0;
		}
	}
	return 1;
}
int ResourceRequestAlgorithm(int Request[], int Need[MAX][MAX], int pid, int Allocation[MAX][MAX], int Available[MAX]) {
	int i, j;
	if (LessThan(Request, Need[pid]) == 1) {
		if (LessThan(Request, Available) == 1) {
			for (i = 0; i < M; i++) {
				Allocation[pid][i] += Request[i];
				Need[pid][i] -= Request[i];
				Available[i] -= Request[i];
			}
			if (SafetyAlgorithm(Need, Allocation, Available) == 1) {
				printf("System is not in  a deadlocked state\n");
				return 1;
			}
			else {
				Allocation[pid][i] += Request[i];
				Need[pid][i] -= Request[i];
				Available[i] -= Request[i];
				printf("System is in an unsafe state. Resources are not allocated\n");
				return 0;
			}
		}
		printf("Process has to wait\n");
	}
	printf("Alert !! Exceeded Max Claim\n");
	return 2;
}
int main() {
	int i, j, Need[MAX][MAX], Allocation[MAX][MAX], Max[MAX][MAX], Available[MAX], Request[MAX], pid;
	printf("Enter the no of processes and no of types of resources respectively\n");
	scanf("%d %d", &N, &M);
	printf("Enter Max resources of each type process by process\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &Max[i][j]);
		}
	}
	printf("Enter allocated resources of each type process by process\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &Allocation[i][j]);
		}
	}
	printf("Enter available resources of each type\n");
	for (j = 0; j < M; j++) {
		scanf("%d", &Available[j]);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			Need[i][j] = Max[i][j] - Allocation[i][j];
		}
	}
	printf("Enter the process Id\n");
	scanf("%d", &pid);
	printf("Enter resources requested by the process\n");
	for (j = 0; j < M; j++) {
		scanf("%d", &Request[j]);
	}
	ResourceRequestAlgorithm(Request, Need, pid, Allocation, Available);
}