#include <stdio.h>
#define INF 1000000001
#define MAX_INDEX 300000

int maxArray[MAX_INDEX], min,
testcase, loop_testcase, n, i, j, pre, cur, result, branch,
start, end, mid;

int main() {
	scanf("%d", &testcase);
	for (loop_testcase = 1; loop_testcase <= testcase; loop_testcase++) {
		result = 0, branch = 0, pre = INF;
		min = INF;
		scanf("%d", &n);

		for (i = 0; i < n; i++) {
			scanf("%d", &cur);

			if (cur < pre) {
				// 브랜치 생성
				if (min > cur) {
					result += branch;
					branch = 0;
					min = cur;
				}
				maxArray[branch++] = cur;
			}
			else if (cur > pre) {
				/* 이진탐색 */

				start = branch, end = 0;

				while (end < start) {
					mid = (start + end) / 2;
					if (maxArray[mid] == cur) {
						start = mid;
						break;
					}
					else if (maxArray[mid] < cur) {
						start = mid;
					}
					else {
						end = mid + 1;
					}
				}

				maxArray[start] = cur;
				branch = start + 1;
			}

			pre = cur;
		}
		printf("#%d %d\n", loop_testcase, result + branch);
	}

	return 0;
}