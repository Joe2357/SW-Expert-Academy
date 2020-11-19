#include <stdio.h>

long long n, i;
int t, testcase;

int main() {
	scanf("%d", &testcase);
	for (t = 1; t <= testcase; ++t) {
		scanf("%lld", &n);
		for (i = 1; i <= 1000000; ++i) {
			if (i*i*i > n) {
				printf("#%d -1\n", t);
				break;
			}
			else if (i*i*i == n) {
				printf("#%d %lld\n", t, i);
				break;
			}
		}
	}
	return 0;
}