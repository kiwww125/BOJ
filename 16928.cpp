//simple bfs

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;

const int INF = -1;

vector<int> d(101, INF);
int adj[101] = { 0, };

void input() {
	int n, m, x, y; cin >> n >> m;
	n += m;
	while (n--) {
		cin >> x >> y;
		adj[x] = y;
	}
}

void solve() {
	
	queue<int> q;
	q.emplace(1);
	d[1] = 0;

	while (q.size()) {
		int cur = q.front(); q.pop();
		if (cur == 100) break;

		if(adj[cur]) {
			d[adj[cur]] = d[cur];
			cur = adj[cur];
		}

		for(int i = 1; i <= 6; i++){
			int nxt = cur + i;
			if (nxt > 100) break; //out of bound check
			if (d[nxt] != INF) continue; //visit check
			d[nxt] = d[cur] + 1; //update dist
			q.emplace(nxt);
		}
 	}

	cout << d[100];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	input();
	solve();

	return 0;
}
