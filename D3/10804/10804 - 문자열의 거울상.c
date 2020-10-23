#include <stdio.h>
#define MAX_INDEX 1000

int t, len, a, b;
char str[MAX_INDEX + 1];
char tml['q' + 1];
char temp;

int main() {

	tml['b'] = 'd';
	tml['d'] = 'b';
	tml['p'] = 'q';
	tml['q'] = 'p';

	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {

		scanf("%s", str);
		for (len = 0; str[len]; len++);

		for (a = 0, b = len - 1; a < b; a++, b--) {

			temp = str[b];

			str[b] = tml[str[a]];

			str[a] = tml[temp];

		}
		if (a == b)
			str[a] = tml[str[a]];

		printf("#%d %s\n", test_case, str);
	}

	return 0;
}