#include <stdio.h>
#define MAX_INDEX 49

int t, n, result;
int i, j, test_case;
char grid[MAX_INDEX][MAX_INDEX + 1];

int main() {

	scanf("%d", &t);
	for (test_case = 1; test_case <= t; test_case++) {

		result = 0;
		scanf("%d", &n);

		for (i = 0; i < n; i++)
			scanf("%s", grid[i]);

		for (i = 0; i < n / 2 + 1; i++)
			for (j = n / 2 - i; j < n / 2 + i + 1; j++)
				result += (grid[i][j] - '0');

		for (i = n / 2 - 1; i >= 0; i--)
			for (j = n / 2 - i; j < n / 2 + i + 1; j++)
				result += (grid[n - i - 1][j] - '0');

		printf("#%d %d\n", test_case, result);
	}

	return 0;
}