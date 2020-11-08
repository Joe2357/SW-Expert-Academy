#include <stdio.h>
#define MAX_LENGTH 10
#define True 1
#define False 0

typedef char boolean;

char str[MAX_LENGTH + 1];
int test_case, t;
int i, j;
boolean isPalindrome;

int main() {

	scanf("%d", &test_case);
	for (t = 1; t <= test_case; ++t) {
		scanf("%s", str);
		isPalindrome = True;

		for (j = 0; str[j]; ++j);
		for (i = 0, --j; i < j; ++i, --j)
			isPalindrome &= (str[i] == str[j]);

		printf("#%d %d\n", t, isPalindrome);
	}

	return 0;
}