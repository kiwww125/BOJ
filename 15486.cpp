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
const ll INF = 1e18;

int n, dp[1500001];
pii v[1500001];

int solve(int i) {
	if (i > n) return 0;
	if (dp[i]) return dp[i];
	
	if (i + v[i].first <= n + 1) dp[i] = solve(i + v[i].first) + v[i].second;
	dp[i] = max(dp[i], solve(i + 1));

	return dp[i];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;
	cout << solve(1);

	return 0;
}
