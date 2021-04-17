// data structure - map / dict

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

map<string, string> dic;

void solve() {
	int n, m; cin >> n >> m;
	string s, p;
	while (n--) {
		cin >> s >> p;
		dic[s] = p;
	}

	while (m--) {
		cin >> s;
		cout << dic[s] << '\n';
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
