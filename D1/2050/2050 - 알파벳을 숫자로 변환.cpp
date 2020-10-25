#include <stdio.h>

char c;

int main() {
	while (~scanf("%c", &c))
		printf("%d ", c - 'A' + 1);

	return 0;
}