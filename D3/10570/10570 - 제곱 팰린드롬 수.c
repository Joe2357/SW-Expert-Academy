#include <stdio.h>
#define MAX_INDEX 1000
#define True 1
#define False 0

typedef char boolean;

boolean isTrue[MAX_INDEX + 1];

int main()
{
	// init
	isTrue[1 * 1] = True;
	isTrue[2 * 2] = True;
	isTrue[3 * 3] = True;
	isTrue[11 * 11] = True;
	isTrue[22 * 22] = True;

	// loop testcase
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		int result = 0;
		int a, b;
		scanf("%d %d", &a, &b);

		for (; b >= a; b--)
			result += isTrue[b];

		printf("#%d %d\n", i, result);
	}

	return 0;
}