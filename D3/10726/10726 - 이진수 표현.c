#include <stdio.h>

int arr[31] = { 1, 2 };

int main() {
	for (int i = 2; i <= 30; i++)
		arr[i] = arr[i - 1] * 2;

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int n;
		long long m;

		scanf("%d %lld", &n, &m);

		printf("#%d ", i);
		printf("%s\n", ((m % arr[n] == arr[n] - 1) ? "ON" : "OFF"));
	}

	return 0;
}