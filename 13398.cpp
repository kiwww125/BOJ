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
const int INF = 1e9;

int a[100001];
int dp[100001][2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i]; 

	dp[0][0] = 0, dp[0][1] = a[0];
	int mx = dp[0][1];
	
	for (int i = 1; i < n; i++) {
		// 이미 하나 빠진경우 / i번째 값을 빼는 경우
		dp[i][0] = max(dp[i - 1][0] + a[i], dp[i - 1][1]);
		dp[i][1] = max(dp[i - 1][1], 0) + a[i];

		mx = max(max(dp[i][0], dp[i][1]), mx);
	}

	cout << mx;
	return 0;
}
