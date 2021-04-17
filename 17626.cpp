//simple DP

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

int dp[50001];

void solve() {
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		int mn = 99999;
		for (int j = 1; j * j <= i; j++) {
			mn = min(mn, dp[i - j * j]);
		}
		dp[i] = mn + 1;
	}

	cout << dp[n];
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
