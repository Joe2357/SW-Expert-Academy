#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
#define MAX_INDEX 10

using namespace std;
typedef struct Position {
	int x, y;
} PS;

int n, result;
PS arr[MAX_INDEX];
PS company;
PS home;

int getDist(PS *a, PS *b) {
	return abs(a->x - b->x) + abs(a->y - b->y);
}

void solve(int current, int dist, int did) {
	bool finished = true;

	for (int i = 0; i < n; i++)

		if ((did & (1 << i)) == 0) {
			solve(i, dist + getDist(arr + current, arr + i), did + (1 << i));
			finished = false;
		}

	if (finished)
		result = min(result, dist + getDist(arr + current, &home));

	return;
}

void input() {
	cin >> n;
	cin >> company.x >> company.y;
	cin >> home.x >> home.y;
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;

	return;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		result = INF;

		input();

		for (int i = 0; i < n; i++)
			solve(i, getDist(&company, arr + i), (1 << i));

		cout << "#" << test_case << " " << result << "\n";
	}

	return 0;
}