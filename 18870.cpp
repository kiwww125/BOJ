#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>

using namespace std;
using ll = long long;

vector<int> v, itp;
set<int> s;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
		s.insert(a);
	}

	for (const auto a : s) itp.push_back(a);

	for (int i = 0; i < n; i++) {
		cout << lower_bound(itp.begin(), itp.end(), v[i]) - itp.begin() << ' ';
	}

	return 0;
}
