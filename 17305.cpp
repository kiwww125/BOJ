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
const ll INF = 1e18;

vector<int> v[6]; 
ll psum3[500001], psum5[250001];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, w; cin >> n >> w;
	for (int i = 0; i < n; i++) {
		int t, s; cin >> t >> s;
		v[t].push_back(s);
	}

	sort(all(v[3]), cmp);
	sort(all(v[5]), cmp);

	for (int i = 1; i <= 500000; i++) {
		if (i > v[3].size()) psum3[i] = psum3[i - 1];
		else psum3[i] = psum3[i-1] + v[3][i - 1];
	}

	for (int i = 1; i <= 250000; i++) {
		if (i > v[5].size()) psum5[i] = psum5[i - 1];
		else psum5[i] = psum5[i - 1] + v[5][i - 1];
	}

  //using psum - find maximum psum3[j] (i * 5 + j * 3 <= w) in O(1)
	ll res = 0;
	for (int i = 0; i * 5 <= w; i++) 
		res = max(res, psum5[i] + psum3[(w - i * 5) / 3]);
	
	cout << res;
	return 0;
}
