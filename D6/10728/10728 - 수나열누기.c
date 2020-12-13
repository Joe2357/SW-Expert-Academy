#include <stdio.h>

typedef struct Node {
	int min, max;
	int minu, maxu;
} ND;

ND arr[300000];

int main() {
	int test_case;
	scanf("%d", &test_case);
	for (int t = 1; t <= test_case; ++t) {
		int n, i, len = 0;
		int a, b;
		scanf("%d %d", &n, &i);
		arr[len = 0] = (ND) { i, i, -1, -1 };
		for (--n; n; --n) {
			scanf("%d", &i);
			if (i >= arr[len].max) {
				arr[len].max = i;
			}
			else {
				b = arr[len].maxu;
				while (b != -1 && arr[b].max <= arr[len].max) { b = arr[b].maxu; }
				arr[len].maxu = b;
				a = arr[len].minu;
				while (a != -1 && a > b && arr[a].min == arr[len].min) {
					arr[len].minu = a;
					a = arr[a].minu;
				}
				while (len > 0) {
					a = arr[len].minu;
					if (a > b) {
						arr[a].max = arr[len].max;
						arr[a].maxu = b;
						len = a;
					}
					else { break; }
				}

				++len;
				arr[len] = (ND) { i, i, len - 1, len - 1 };
				a = arr[len].minu;
				while (a != -1 && arr[a].min > arr[len].min) {
					arr[len].minu = (a = arr[a].minu);
				}
			}
		}

		b = arr[len].maxu;
		while (b != -1 && arr[b].max <= arr[len].max) { b = arr[b].maxu; }
		arr[len].maxu = b;
		a = arr[len].minu;
		while (a != -1 && a > b && arr[a].min == arr[len].min) {
			arr[len].minu = a;
			a = arr[a].minu;
		}
		while (len > 0) {
			a = arr[len].minu;
			if (a > b) {
				arr[a].max = arr[len].max;
				arr[a].maxu = b;
				len = a;
			}
			else { break; }
		}

		printf("#%d %d\n", t, len + 1);
	}
	return 0;
}