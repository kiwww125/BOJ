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
const int INF = 1e9;
const int n = 9;

char board[9][9];
bool rows[9][10], cols[9][10];

bool solve(int r, int c) {
	int nr = c == 8 ? r + 1 : r;
	int nc = c == 8 ? 0 : c + 1;

	if (r == n) return true;
	if (board[r][c]) return solve(nr, nc);
	
	//board[r][c] = 0;
	for (int num = 1; num <= 9; num++) {
		bool skip = false;
		if (rows[r][num] || cols[c][num]) skip = true;
		for (int rr = (r / 3) * 3, dr = 0; dr < 3; dr++) {
			for (int cc = (c / 3) * 3, dc = 0; dc < 3; dc++) {
				if (board[rr + dr][cc + dc] == num) 
					skip = true;
			}
		}
		if (skip) continue;

		rows[r][num] = cols[c][num] = true;
		board[r][c] = num;

		if (solve(nr, nc)) return true;
    
		rows[r][num] = cols[c][num] = false;
		board[r][c] = 0;
	}

	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			board[i][j] -= '0';
			if (board[i][j]) rows[i][board[i][j]] = cols[j][board[i][j]] = true;
		}
	
	solve(0, 0);

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cout << (char)(board[i][j] +'0') << (j == n - 1 ? "\n" : "");

	return 0;
}
