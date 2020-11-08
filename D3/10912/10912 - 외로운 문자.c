#include <stdio.h>
#define MAX_INDEX 100
#define True 1
#define False 0

typedef char boolean;

char str[MAX_INDEX + 1];

int main() {

	int test_case;
	scanf("%d", &test_case);
	for (int t = 1; t <= test_case; t++) {
		boolean result = False;
		scanf("%s", str);

		boolean alpha[27] = { False };
		for (int i = 0; str[i]; i++)
			alpha[str[i] - 'a'] = !alpha[str[i] - 'a'];

		printf("#%d ", t);
		for (int i = 0; i < 26; i++)
			if (alpha[i]) {
				result = True;
				printf("%c", i + 'a');
			}

		if (!result)
			printf("Good");
		printf("\n");
	}

	return 0;
}