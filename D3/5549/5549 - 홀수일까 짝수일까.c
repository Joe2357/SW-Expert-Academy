#include <stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	char result[2][5] = { "Even", "Odd" };

	for (int i = 1; i <= t; i++) {

		char str[101];
		scanf("%s", str);

		int a = 0;
		for (; str[a]; a++);
		printf("#%d %s\n", i, result[str[--a] % 2]);
	}

	return 0;
}