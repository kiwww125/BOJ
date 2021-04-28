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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c; cin >> n >> c;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (c == v[i]) ans = 1;
		for (int j = i + 1; j < n; j++) {
			if (c == v[i] + v[j]) ans = 1;
		
			auto iter = lower_bound(v.begin(), v.end(), c - (v[i] +  v[j]));
			if (iter == v.end()) continue;
			if (*iter == v[i] || *iter == v[j]) continue;
			if (*iter == c - (v[i] + v[j])) ans = 1;
		}
	}

	cout << ans;
	return 0;
}
