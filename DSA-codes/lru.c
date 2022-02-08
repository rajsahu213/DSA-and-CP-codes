#include<stdlib.h>
#include<stdio.h>
int main(void *arg, int argc) {
	int l; printf("enter the size of string\n"); scanf("%d", &l);
	char c[l]; printf("enter the string\n"); scanf("%s", c);
	int f; printf("enter the frame size  "); scanf("%d", &f);
	int cnt = 0;
	int arr[f]; int page_fault = 0;
	for (int i = 0; i < l; i++) {
		int p = (int)(c[i] - '0');
		//find page
		int fl = 0;
		for (int j = 0; j < cnt; j++) {
			if (arr[j] == p) {
				fl = 1; break;
			}
		}
		//if empty
		if (fl == 0) {
			if (f > cnt) {
				arr[cnt] = p;
				cnt++;
			}
			else {
				for (int j = 1; j < f - 1; j++) {
					arr[j - 1] = arr[j];
				}
				arr[f - 1] = p;
			}
			page_fault++;
		}
		else {
			int fl2 = 0;
			for (int j = 0; j < cnt; j++) {
				if (fl2 == 1) {
					arr[j - 1] = arr[j];
				}
				if (arr[j] == p) {
					fl2 = 1;
				}

			}
			arr[f - 1] = p;
		}
	}
	printf("no of page fault %d", page_fault);
	printf("\n");
	return 0;
}