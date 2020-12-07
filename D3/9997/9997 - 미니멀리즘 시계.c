#include <stdio.h>

int test_case, t;
int n;

int main() {
	scanf("%d", &test_case);
	for (t = 1; t <= test_case; ++t) {
		scanf("%d", &n);
		printf("#%d %d %d\n", t, n / 30, (n % 30) * 2);
	}
	return 0;
}