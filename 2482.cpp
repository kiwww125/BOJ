#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>

#define x first
#define y second
#define all(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll , ll>;
using pis = pair<int, string>;
const ll MOD = 1e9 + 3;

ll dp[1001][1001];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	for (int j = 1; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			if (j == 1) dp[i][j] = i;
			else if (j * 2 <= i) dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
		}
	}

	cout << dp[n][k];
	return 0;
}
