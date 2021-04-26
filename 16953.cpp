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

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll , ll> ;
const ll INF = 1e18;

void solve() {
	ll a, b, ans = -1;
	cin >> a >> b;
	queue<pll> q;
	q.emplace(pll(1, a));


	while (q.size()) {
		pll cur = q.front(); q.pop();
		ll time = cur.first, num = cur.second;

		if (num == b) {
			ans = time;
			break;
		}

		if (num * 2 <= b) q.emplace(pll(time + 1, num * 2));
		if (num * 10 + 1 <= b) q.emplace(pll(time + 1, num * 10 + 1));
	}

	cout << ans;
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
