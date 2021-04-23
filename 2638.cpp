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
const ll INF = 1e18;

const int dr[] = { 0,0,1,-1 };
const int dc[] = { 1,-1,0,0 };

int n, m;
bool vis[101][101];
int board[101][101]; //2 - outter air, 1- cheese, 0 - inner air

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> board[i][j];
	board[0][0] = 2;
}

bool isBound(int r, int c) {
	return (0 <= r && r < n && 0 <= c && c < m);
}

//update 0 -> 2
void update() {

	queue<pii> q;
	q.emplace(pii(0, 0));
	
	for (int i = 0; i < n; i++) fill_n(vis[i], m, false);
	vis[0][0] = true;

	while (q.size()) {
		pii cur = q.front(); q.pop();

		for (int d = 0; d < 4; d++) {
			int r = cur.x + dr[d], c = cur.y + dc[d];
			if (!isBound(r, c)) continue;
			if (vis[r][c]) continue;
			if (board[r][c] == 1) continue;
			
			//0, 2 && not visited
			vis[r][c] = true;
			board[r][c] = 2;
			q.emplace(pii(r, c));
		}
	}
}

bool melt() {
	vector<pii> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {
				int cnt = 0;
				for (int d = 0; d < 4; d++) {
					int r = i + dr[d], c = j + dc[d];
					if (board[r][c] == 2) cnt++;
				}
				if (cnt >= 2) v.emplace_back(pii(i, j));
			}
		}
	}

	for (pii a : v) board[a.x][a.y] = 2;
	return (int)v.size();
}


void solve() {
	
	int res = 0;
	while (1) {
		update();
		if (!melt()) break;
		res++;
	}

	cout << res;
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
