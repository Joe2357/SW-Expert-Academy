#include <stdio.h>
#define MAX_INDEX 10

int ret[MAX_INDEX + 1];

void backtrack(int size, int use, int* fit, bool* isUsed, int* used) {
	if (size == use) {
		*fit += 1;
		return;
	}

	for (int i = 0; i < size; ++i) {
		if (!isUsed[i]) {
			bool cannotFit = false;
			for (int a = 0; a < use && !cannotFit; ++a)
				cannotFit = cannotFit || ((use - a == i - used[a]) || (use - a == used[a] - i));
			if (!cannotFit) {
				isUsed[i] = true, used[use] = i;
				backtrack(size, use + 1, fit, isUsed, used);
				isUsed[i] = false;
			}
		}
	}

	return;
}

void init() {
	for (int i = 1; i <= 10; ++i) {
		bool isUsed[MAX_INDEX] = { false };
		int used[MAX_INDEX] = { 0 };
		backtrack(i, 0, &ret[i], isUsed, used);
	}
	return;
}

int main() {
	init();
	int test_case;
	scanf("%d", &test_case);
	for (int t = 1; t <= test_case; ++t) {
		int n;
		scanf("%d", &n);
		printf("#%d %d\n", t, ret[n]);
	}
	return 0;
}