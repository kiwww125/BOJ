#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>

using namespace std;
using ll = long long;

struct Heap {

	vector<int> tree;
	Heap() {
		tree.assign(1, 0);
	}

	//bubble up
	void push(int a) {
		int i = tree.size();
		tree.push_back(a);
		while (i != 1 && tree[i] > tree[i / 2]) {
			swap(tree[i], tree[i / 2]);
			i /= 2;
		}
	}

	//trickle down
	int pop() {
		int i = 1, c = 2, ret = tree[i];
		tree[i] = tree.back();

		while (c < tree.size()) {		
			if (c + 1 < tree.size() && tree[c] < tree[c + 1]) c += 1;
			if (tree[i] > tree[c]) break;
			swap(tree[i], tree[c]);
			i = c;
			c *= 2;
		}

		tree.pop_back();
		return ret;
	}

	bool empty() {
		return tree.size() == 1;
	}
};

Heap heap;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	while (n--) {
		int a; cin >> a;
		if (a == 0) {
			if (heap.empty()) cout << 0 << '\n';
			else cout << heap.pop() << '\n';
		}
		else heap.push(a);
	}

	return 0;
}
