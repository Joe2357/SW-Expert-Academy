#include <iostream>
#define MAX_INDEX 10

using namespace std;

int arr[10][10];
int t;

void init() {
	for (int i = 0; i < MAX_INDEX * MAX_INDEX; i++)
		arr[i / 10][i % 10] = -1;

	return;
}

void solve(int n) {
	int dir = 0;
	int x = 0, y = 0;

	for (int number = 1; number <= n * n; number++) {
		arr[y][x] = number;

		switch (dir) {
			case 0:
				if (x == n - 1 || arr[y][x + 1] != -1)
					y++, dir++;
				else x++;
				break;
			case 1:
				if (y == n - 1 || arr[y + 1][x] != -1)
					x--, dir++;
				else y++;
				break;
			case 2:
				if (x == 0 || arr[y][x - 1] != -1)
					y--, dir++;
				else x--;
				break;
			case 3:
				if (y == 0 || arr[y - 1][x] != -1)
					x++, dir = 0;
				else y--;
				break;
		}
	}
}

void print_result(int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {

		init();

		int n;
		cin >> n;

		solve(n);

		cout << "#" << test_case << "\n";
		print_result(n);
	}

	return 0;
}