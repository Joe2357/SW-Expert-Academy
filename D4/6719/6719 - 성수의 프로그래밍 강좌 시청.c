#include <stdio.h>

int a[200];

int cmp(int* a, int* b) {
	return *a > *b;
}

int main() {
	int test_case;
	scanf("%d", &test_case);
	for (int t = 1; t <= test_case; ++t) {
		int n, k;
		double ret = 0.0;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		qsort(a, n, sizeof(int), cmp);
		for (int i = n - k; i < n; ++i) {
			ret = (ret + a[i]) / 2;
		}
		printf("#%d %lf\n", t, ret);
	}
	return 0;
}