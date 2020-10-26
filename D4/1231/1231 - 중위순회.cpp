#include <stdio.h>
#define MAX_VERTAX 101

char tree[MAX_VERTAX + 1];
char str[12];
int length;
int test_case;

void inorder(int num) {

	if (length >= num * 2)
		inorder(num * 2);

	printf("%c", tree[num]);

	if (length >= num * 2 + 1)
		inorder(num * 2 + 1);

	return;
}

int main() {

	for (test_case = 1; test_case <= 10; test_case++) {

		scanf("%d", &length);
		getchar();

		for (int i = 0; i < length; i++) {

			gets(str);
			// printf("%d : %s\n", i, str);

			int a = 0, j;
			for (j = 0; str[j] != ' '; j++)
				a *= 10, a += (str[j] - '0');

			tree[a] = str[++j];
		}

		printf("#%d ", test_case);
		inorder(1);
		printf("\n");

	}

	return 0;
}