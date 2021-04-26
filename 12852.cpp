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

vector<bool> vis(1000001, false);

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	queue<pis> q;
	q.emplace(pis(n, ""));

	while (q.size()) {
		pis cur = q.front(); q.pop();
		int num = cur.first;
		string oper = cur.second;

		if (num < 1) continue;

		if (num == 1) {
			cout << oper.size() << '\n';
			cout << n << ' ';
			for (char c : oper) {
				if (c == '1') n /= 3;
				if (c == '2') n /= 2;
				if (c == '3') n -= 1;
				cout << n << ' ';
			}
			break;
		}

		if (!vis[num / 3] && num % 3 == 0) {
			vis[num / 3] = true;
			q.emplace(pis(num / 3, oper + "1"));
		}
		if (!vis[num / 2] && num % 2 == 0) {
			vis[num / 2] = true;
			q.emplace(pis(num / 2, oper + "2"));
		}
		if (!vis[num - 1]) {
			vis[num - 1] = true;
			q.emplace(pis(num - 1, oper + "3"));
		}
	}

	return 0;
}
