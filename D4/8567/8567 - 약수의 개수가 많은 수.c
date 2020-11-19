#include <stdio.h>
#define MAX_INDEX 100000

int dp[2][MAX_INDEX + 1];
int t, testcase;
int n;
int i, j;

void init() {
	for (i = 1; i <= MAX_INDEX; ++i)
		for (j = i; j <= MAX_INDEX; j += i)
			++dp[0][j];

	for (i = 1; i <= MAX_INDEX; ++i)
		if (dp[0][dp[1][i - 1]] <= dp[0][i])
			dp[1][i] = i;
		else dp[1][i] = dp[1][i - 1];

	return;
}

int main() {
	init();
	scanf("%d", &testcase);
	for (t = 1; t <= testcase; ++t) {
		scanf("%d", &n);
		printf("#%d %d\n", t, dp[1][n]);
	}
	return 0;
}