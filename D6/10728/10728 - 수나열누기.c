#include <stdio.h>
#define MAX_INDEX 300000

typedef struct Node
{
	int value;
	int index;
} ND;

int arr[MAX_INDEX], length;
ND asc[MAX_INDEX], desc[MAX_INDEX];
int result;

int asc_cmp(ND *a, ND *b)
{
	if (a->value != b->value)
		return a->value > b->value;
	else
		return a->index > b->index;
}

int desc_cmp(ND *a, ND *b)
{
	if (a->value != b->value)
		return a->value < b->value;
	else
		return a->index < b->index;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		result = 0;
		scanf("%d", &length);
		for (int a = 0; a < length; a++)
		{
			scanf("%d", arr + a);
			asc[i] = (ND){arr[a], i + 1};
			desc[i] = (ND){arr[a], i + 1};
		}

		qsort(asc, length, sizeof(ND), asc_cmp);
		qsort(desc, length, sizeof(ND), desc_cmp);

		printf("#%d %d\n", i, result);
	}

	return 0;
}