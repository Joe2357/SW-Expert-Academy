#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_INDEX 1000

int stack[MAX_INDEX], n, result;

int main() {

	for (int test_case = 1; test_case <= 10; test_case++) {

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", stack + i);

		for (int i = 2; i < n - 2; i++) {

			int m = max(max(stack[i - 2], stack[i - 1]), max(stack[i + 1], stack[i + 2]));
			result += ((stack[i] > m) ? stack[i] - m : 0);
		}

		printf("#%d %d\n", test_case, result);
	}

	return 0;
}