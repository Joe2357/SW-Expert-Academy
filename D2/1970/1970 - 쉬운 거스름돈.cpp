#include <stdio.h>

int coin[] = { 50000,10000,5000,1000,500,100,50,10 };
int test_case, t;
int n;
int i;

int main() {
	scanf("%d", &test_case);
	for (t = 1; t <= test_case; ++t) {
		scanf("%d", &n);
		printf("#%d\n", t);
		for (i = 0; i < 8; ++i) {
			printf("%d ", n / coin[i]);
			n %= coin[i];
		}
		printf("\n");
	}
	return 0;
}