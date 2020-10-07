#include <stdio.h>
#include <math.h>

long long solve(long long n)
{
	long long result = 0;

	while (n != 2)
	{
		if (n == 1)
		{
			result++;
			break;
		}

		long long square = (long long)sqrt(n);

		if (square * square != n)
			square++;

		result += (square * square - n);
		result++, n = square;
	}

	return result;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		long long n;
		scanf("%lld", &n);
		printf("#%d %lld\n", i, solve(n));
	}

	return 0;
}