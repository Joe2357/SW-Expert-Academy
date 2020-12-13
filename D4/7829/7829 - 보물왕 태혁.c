#include <stdio.h>

int main() {
	int test_case;
	scanf("%d", &test_case);
	for (int t = 1; t <= test_case; ++t) {
		int n;
		int min = 1000001, max = -1;
		int a;
		scanf("%d", &n);
		for (; n; --n) {
			scanf("%d", &a);
			min = ((min > a) ? a : min);
			max = ((max < a) ? a : max);
		}
		printf("#%d %d\n", t, max * min);
	}
	return 0;
}