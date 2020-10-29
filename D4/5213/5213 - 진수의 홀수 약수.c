#include <stdio.h>
#define MAX_INDEX 1000000

long long arr[MAX_INDEX + 1];

void init() {
	for (int i = 1; i <= MAX_INDEX; i += 2)
		for (int j = i; j <= MAX_INDEX; j += i)
			arr[j] += i;

	long long temp = 0;
	for (int i = 0; i <= MAX_INDEX; i++) {
		temp += arr[i];
		arr[i] = temp;
	}

	return;
}

int main() {

	init();

	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		int a, b;
		scanf("%d %d", &a, &b);

		printf("#%d %lld\n", test_case, arr[b] - arr[a - 1]);
	}

	return 0;
}