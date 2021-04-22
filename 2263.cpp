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

int n;
vector<int> adj[100001], in, post;

//포스트 오더의 마지막 = 트리의 루트,
//루트를 기준으로 분할 - subtree에 동일한 로직 적용.

void input() {
	cin >> n;
	in = post = vector<int>(n);
	for (int& a : in) cin >> a;
	for (int& a : post) cin >> a;
}

//[0, n) range
int dfs(int ins, int ine, int posts, int poste) {
	
  //no node ex. [1,1)
	if (posts >= poste) return 0;
	//leaf node ex. [1, 2)
  if (posts + 1 == poste) return post[posts];

	int root = post[poste - 1], mid = ins;
	while (in[mid] != root) mid++;

	//left, right subtree
	adj[root].push_back(dfs(ins, mid, posts, posts + mid - ins));
	adj[root].push_back(dfs(mid + 1, ine, posts + mid - ins, poste - 1));
  
	return root;
}

void pre(int cur) {
	cout << cur << ' ';
	for (int next : adj[cur])
		if(next) pre(next);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	input();
	pre(dfs(0, n, 0, n));
	
	return 0;
}
