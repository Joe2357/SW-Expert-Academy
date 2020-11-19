#include <stdio.h>

typedef char boolean;
#define True 1
#define False 0

typedef struct Node {
	boolean isNumber;
	double number;
	char op;
	int left, right;
} ND;

#define MAX_INDEX 1000 + 1
ND arr[MAX_INDEX];
char input[101];
int n;
int test_case;

void read_input() {
	getchar();
	for (int i = 0; i < n; ++i) {
		gets(input);
		int num = 0, j;
		for (j = 0; input[j] != ' '; ++j)
			num *= 10, num += (input[j] - '0');
		++j;
		if (input[j] >= '0' && input[j] <= '9') {
			arr[num].isNumber = True;
			double temp = 0;
			for (; input[j]; ++j)
				temp *= 10, temp += (input[j] - '0');
			arr[num].number = temp;
		}
		else {
			arr[num].isNumber = False;
			arr[num].op = input[j];
			int l = 0, r = 0;
			for (j += 2; input[j] != ' '; ++j)
				l *= 10, l += (input[j] - '0');
			for (++j; input[j]; ++j)
				r *= 10, r += (input[j] - '0');
			arr[num].left = l, arr[num].right = r;
		}
	}
	return;
}

double solve(int x) {
	if (arr[x].isNumber)
		return arr[x].number;
	else {
		double ret;
		switch (arr[x].op) {
			case '+':
				ret = solve(arr[x].left) + solve(arr[x].right);
				break;
			case '-':
				ret = solve(arr[x].left) - solve(arr[x].right);
				break;
			case '*':
				ret = solve(arr[x].left) * solve(arr[x].right);
				break;
			case '/':
				ret = solve(arr[x].left) / solve(arr[x].right);
				break;
		}
		return ret;
	}
}

int main() {
	while (~scanf("%d", &n)) {
		read_input();
		printf("#%d %d\n", ++test_case, (int)solve(1));
	}
	return 0;
}