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
using pll = pair<ll , ll>;
using pis = pair<int, string>;
const ll INF = 1e18;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, n, m;
	cin >> t;
	
	cin >> n;
	vector<int> a(n);
	map<int, int> am;
	for (int& i : a) cin >> i;
	for (int i = 0; i < n; i++) {
		int v = 0;
		for (int j = i; j < n; j++) {
			v += a[j];
			am[v] += 1;
		}
	}
	
	cin >> m;
	vector<int> b(m);
	map<int, int> bm;
	for (int& i : b) cin >> i;
	for (int i = 0; i < m; i++) {
		int v = 0;
		for (int j = i; j < m; j++) {
			v += b[j];
			bm[v] += 1;
		}
	}

	ll res = 0;
	for (auto iter = am.begin(); iter != am.end(); iter++) {
		pii now = *iter;
		int v = now.first, cnt = now.second;

		auto tar = bm.find(t - v);
		if (tar != bm.end()) {
			res += (ll)(*tar).second * cnt;
		}
	}

	cout << res;
	return 0;
}
