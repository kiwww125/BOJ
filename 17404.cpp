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

#define x first
#define y second
#define all(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll , ll>;
using pis = pair<int, string>;
const int INF = 1e9;

int n; 
int c[1001][3]; //0 ~ n - 1
int dp[1001][3];

int solve(int color) {
	
	for (int i = 0; i < 3; i++) {
		if (i == color) dp[0][i] = c[0][i];
		else dp[0][i] = INF;
	}

	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + c[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + c[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + c[i][2];
	}

	int res = INF;
	for (int i = 0; i < 3; i++) {
		if (i == color) continue;
		res = min(res, dp[n - 1][i]);
	}

	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < 3; j++) 
			cin >> c[i][j];

	int res = min(min(solve(0), solve(1)), solve(2));
	cout << res;
	return 0;
}
