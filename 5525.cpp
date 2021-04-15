#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>

using namespace std;
using ll = long long;

int solve() {
	int n, m;
	string s;
	cin >> n >> m;
	cin >> s;

	int res = 0, i = s.find('I');
	if (i != -1) {
		for (int j = i + 1; j < m; j++) {
			if (s[j] == s[j - 1]) {
				while (j < m && s[j] == s[j - 1]) j++;
				//out of bound
				if (j == m) break;

				//III...IO
				if (s[j] == 'O') i = j - 1;
				//OOO...OI
				else i = j;
			}
			//found matching
			if (j - i + 1 == 2 * n + 1) {
				res++;
				i += 2;
			}
		}
	}
	return res;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << solve();

	return 0;
}
