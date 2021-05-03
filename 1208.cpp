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

int n, s;
int a[41];
map <int, int>cntl, cntr; //num, cnt

void btrack(int i, int e, int sum, bool left) {
	if (i == e) {
		if (left) cntl[sum] += 1;
		else cntr[sum] += 1;
		return;
	}

	btrack(i + 1, e, sum + a[i], left);
	btrack(i + 1, e, sum, left);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	btrack(0, n / 2, 0, true);
	btrack(n / 2, n, 0, false);
	cntl[0] -= 1, cntr[0] -= 1;

	ll cnt = 0;
	if (cntl.find(s) != cntl.end()) cnt += cntl[s];
	if (cntr.find(s) != cntr.end()) cnt += cntr[s];

	for (const auto iter : cntl) {
		if (cntr.find(s - iter.first) != cntr.end()) cnt += (ll)iter.second * cntr[s - iter.first];
	}

	cout << cnt;
	return 0;
}
