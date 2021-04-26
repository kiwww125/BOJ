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
	
	int n; cin >> n;
	ll ab = INF;
	vector<int> v(n), res(3);
	
	for (auto& i : v) cin >> i;
	
	sort(v.begin(), v.end());

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			ll t = v[i] + v[j];
			int ind = lower_bound(v.begin(), v.end(), -t) - v.begin();
		
			if (ind < n && abs(t + v[ind]) < ab) {
				if (i != ind && j != ind) {
					ab = abs(t + v[ind]);
					res[0] = v[i], res[1] = v[j], res[2] = v[ind];
				}
			}
	
			ind -= 1;
			if (ind >= 0 && abs(t + v[ind]) < ab) {
				if (i != ind && j != ind) {
					ab = abs(t + v[ind]);
					res[0] = v[i], res[1] = v[j], res[2] = v[ind];
				}
			}
		}
	}
	sort(res.begin(), res.end());
	for (int a : res) cout << a << ' ';
	
	return 0;
}
