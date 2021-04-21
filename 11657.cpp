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

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 1e18;

int n, m, w;
vector<ll> dist;
vector<pii> adj[501];

void input() {
	dist = vector<ll>(501, INF);
	dist[1] = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, e; cin >> u >> v >> e;
		adj[u].emplace_back(pii(v, e));
	}
}

void solve() {

	bool cycle = false;
	for (int i = 1; i <= n; i++) {
		for (int cur = 1; cur <= n; cur++) {
			for (pii p : adj[cur]) {
				int next = p.first, cost = p.second;
				if (dist[cur] != INF && dist[cur] + cost < dist[next]) {
					dist[next] = dist[cur] + cost;
          // At last iteration, if relaxation occur, then 'negative' cycle exists
					if (i == n) cycle = true;
				}
			}
		}
	}

	if (cycle) cout << -1 << '\n';
	else {
		for (int i = 2; i <= n; i++) 	
			cout << (dist[i] != INF ? dist[i] : -1) << '\n';
	}
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
