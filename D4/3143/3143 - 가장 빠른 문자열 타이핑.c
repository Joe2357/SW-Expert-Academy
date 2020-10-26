#include <stdio.h>
#define MAX_INDEX 100

int t, result;
char str[MAX_INDEX*MAX_INDEX + 1], search[MAX_INDEX];
int l1, l2;
int i, j;

int main() {

	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {

		result = 0;
		scanf("%s %s", str, search);
		for (l1 = 0; str[l1]; l1++);
		for (l2 = 0; search[l2]; l2++);

		for (i = 0; i <= l1 - l2; i++) {
			if (str[i] == search[0]) {
				for (j = 0; j < l2; j++)
					if (str[i + j] != search[j])
						break;
				if (j == l2)
					i += (l2 - 1);
			}
			result++;
		}

		printf("#%d %d\n", test_case, result + (l1 - i));
	}

	return 0;
}