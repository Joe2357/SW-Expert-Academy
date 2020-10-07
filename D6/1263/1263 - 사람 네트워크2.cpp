#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define MAX_INDEX 1000

using namespace std;
typedef struct Node {
	int target, moved;
} ND;

bool matrix[MAX_INDEX][MAX_INDEX];
bool visited[MAX_INDEX];
int result[MAX_INDEX];
int n;

void init(int a) {
	for (int i = 0; i < n; i++) {
		visited[i] = (a == i);
		result[i] = INF;
	}

	return;
}

void read_input() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			matrix[j][i] = (a == 1) ? true : false;
		}

	return;
}

int solve() {
	int retval = INF;

	for (int i = 0; i < n; i++) {
		init(i);

		queue<ND> q;
		q.push({ i, 0 });

		// bfs
		while (!q.empty()) {
			ND node = q.front();
			q.pop();

			result[node.target] = min(result[node.target], node.moved);

			for (int j = 0; j < n; j++)
				if (!visited[j] && matrix[node.target][j]) {
					visited[j] = true;
					q.push({ j, node.moved + 1 });
				}
		}

		int temp = 0;
		for (int j = 0; j < n; j++)
			temp += result[j];

		retval = min(retval, temp);
	}

	return retval;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		read_input();

		cout << "#" << test_case << " " << solve() << "\n";
	}

	return 0;
}