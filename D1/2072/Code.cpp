#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int result = 0;
		for (int i = 0; i < 10; i++) {
			int a;
			cin >> a;

			if (a % 2 == 1)
				result += a;
		}

		cout << "#" << test_case << " " << result << "\n";
	}

	return 0;
}