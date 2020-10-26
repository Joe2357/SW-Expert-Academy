#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX_LENGTH 400

using namespace std;

vector<string> grid;
int test_case, t;
string str;
int k, i;

bool cmp(string a, string b) {
	return a < b;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> t;
	for (test_case = 1; test_case <= t; test_case++) {

		grid.clear();
		cin >> k >> str;

		for (i = 0; i < str.length(); i++)
			grid.push_back(str.substr(i, str.length() - i));

		sort(grid.begin(), grid.end(), cmp);

		cout << "#" << test_case << " ";
		if (k > i)
			cout << "none\n";
		else
			cout << grid[k - 1] << "\n";
	}

	return 0;
}