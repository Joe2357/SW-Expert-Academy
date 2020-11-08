#include <stdio.h>
#define max(a, b) (a > b) ? a : b
#define min(a, b) (a < b) ? a : b
#define MAX_VALUE 10000

int minValue, maxValue;
int t, test_case;
int sum, result;
int i, input;

int main() {
	scanf("%d", &test_case);
	for (t = 1; t <= test_case; ++t) {

		sum = 0, minValue = MAX_VALUE + 1, maxValue = -1;
		for (i = 0; i < 10; ++i) {
			scanf("%d", &input);
			sum += input;
			minValue = min(minValue, input);
			maxValue = max(maxValue, input);
		}

		sum -= (minValue + maxValue);
		result = sum / 8;
		if (sum % 8 >= 4)
			++result;

		printf("#%d %d\n", t, result);
	}

	return 0;
}