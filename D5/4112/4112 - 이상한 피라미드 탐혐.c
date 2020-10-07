#include <stdio.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define MAX_INDEX 142

typedef struct Node
{
	int row, col;
} ND;

int arr[MAX_INDEX + 1] = {0, 1};
int n;
int a, b;
ND A, B;

int abs(int x)
{
	if (x < 0)
		x *= -1;

	return x;
}

void init()
{
	for (int i = 2; i <= MAX_INDEX; i++)
		arr[i] = arr[i - 1] + i;

	return;
}

void getNode(ND *nd, int x)
{
	int i = 0;
	while (x > arr[i])
		i++;
	nd->row = i, nd->col = (i - (arr[i] - x));

	return;
}

int getDistance(int x, int y)
{
	getNode(&A, x), getNode(&B, y);
	
	// printf("A : %d %d, B : %d %d\n", A.row, A.col, B.row, B.col);

	if (A.row > B.row)
	{
		ND temp = A;
		A = B, B = temp;
	}

	if (A.row == B.row)
		return abs(B.col - A.col);
	else if (A.col <= B.col && B.col <= A.col + B.row - A.row)
		return B.row - A.row;
	else
		return B.row - A.row + min(abs(B.col - (A.col + B.row - A.row)), abs(B.col - A.col));
}

int main()
{
    init();
    
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d %d", &a, &b);

		printf("#%d %d\n", i, getDistance(a, b));
	}

	return 0;
}