#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
using ll = long long;

int cnt[2] = { 0,0 };

// count the number of 2, 5 in n
void countUp(int n) {
	while (n % 2 == 0 || n % 5 == 0) {
		if (n % 2 == 0) { cnt[0]++; n /= 2; }
		if (n % 5 == 0) { cnt[1]++; n /= 5; }
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for (auto i = 1; i <= n; i++) 
		countUp(i);
		
	cout << min(cnt[0], cnt[1]);

	return 0;
}
