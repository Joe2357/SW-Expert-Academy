#include <stdio.h>
#define MAX_INDEX 1000

int arr[MAX_INDEX + 1];

void init() {
	for (int i = 0; i < 1000; i += 10)
		arr[i + 3]++, arr[i + 6]++, arr[i + 9]++;

	for (int i = 0; i < 1000; i += 100)
		for (int j = 30; j <= 90; j += 30)
			for (int k = 0; k < 10; k++)
				arr[i + j + k]++;

	for (int i = 300; i <= 900; i += 300)
		for (int j = 0; j < 100; j++)
			arr[i + j]++;

	return;
}

int main() {
	init();

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		switch (arr[i]) {
			case 0:
				printf("%d ", i);
				break;
			case 1:
				printf("- ");
				break;
			case 2:
				printf("-- ");
				break;
			case 3:
				printf("--- ");
				break;
		}
	}

	return 0;
}