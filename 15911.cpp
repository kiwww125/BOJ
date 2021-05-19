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
const ll MOD = 1e9 + 9;

ll a[100001];
ll dp[100001];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc; cin >> tc;
	
	a[1] = 1, a[2] = 2, a[3] = 4;
	for (int i = 4; i < 100001; i++) a[i] = ((a[i - 1] + a[i - 2]) % MOD + a[i - 3]) % MOD;

	dp[1] = 1, dp[2] = 2, dp[3] = 2;
	for (int i = 4; i < 100001; i++) {
		if (i % 2) dp[i] = (a[(i - 1) / 2] + a[(i - 3) / 2]) % MOD;
		else dp[i] = (a[i/2] + a[(i - 2) / 2]) % MOD; 
	}

	while (tc--) {
		int n; cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}
