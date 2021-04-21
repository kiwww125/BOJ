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

int n, m, w,s,e;
vector<ll> dist;
vector<pii> adj[1001];

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].emplace_back(pii(v, c));
	}
	cin >> s >> e;
}

void solve() {

	dist = vector<ll>(1001, INF);
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(dist[s], s));
	
	while (pq.size()) {
		pii now = pq.top(); pq.pop();
		int cur = now.second;
		
    //found path s-e
		if (cur == e) break;

		for (pii p : adj[cur]) {
			int next = p.first, cost = p.second;
      // can update min dist
			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				pq.push(pii(dist[next], next));
			}
		}
	}

	cout << dist[e];
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
