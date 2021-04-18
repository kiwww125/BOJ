#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <functional>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <complex>
#include <climits>
#include <list>

#define x first
#define y second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

//right = +1, left = -1 0~3
const ll dx[] = { 1,0,-1,0 };
const ll dy[] = { 0,-1,0,1 };

vector<pll> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, n, dir = 0;
    pll p = pll(0, 0);
    cin >> l >> n;

    v.push_back(p);
    while (n--) {
        ll t;
        string s;
        cin >> t >> s;

        //move
        p = pll(p.x + t * dx[dir], p.y + t * dy[dir]);
        //turn
        if (s[0] == 'L') dir = (dir - 1 + 4) % 4;
        else dir = (dir + 1) % 4;

        v.push_back(p);
    }
    v.push_back(pll(p.x + 2 * 10e8 * dx[dir], p.y + 2 * 10e8 * dy[dir]));
    
    ll die = 0;
    for (int i = 1; i < (int)v.size(); i++) {
        die += (abs(v[i].x - v[i - 1].x) + abs(v[i].y - v[i - 1].y));

        ll mx = -1;
        pll b = v[i - 1], e = v[i];
        //v[i]-v[i-1]
        //v[j]-v[j-1] 비교
        for (int j = i - 2; j > 0; j--) {
            pll bb = v[j - 1], ee = v[j];

            //b | e, bb - ee
            if (b.x == e.x) {
                //y가 안쪽에 있고 x도 안쪽에 있는 경우
                if (((b.y <= bb.y && bb.y <= e.y) || (e.y <= bb.y && bb.y <= b.y)) &&
                    ((bb.x <= e.x && e.x <= ee.x) || (ee.x <= e.x && e.x <= bb.x))) {
                    mx = max(abs(e.y - bb.y), mx);
                }
            }

            //b - e, bb | ee
            if (b.y == e.y) {
                //y가 안쪽에 있고 x도 안쪽에 있는 경우
                if (((bb.y <= b.y && b.y <= ee.y) || (ee.y <= b.y && b.y <= bb.y)) &&
                    ((b.x <= ee.x && ee.x <= e.x) || (e.x <= ee.x && ee.x <= b.x))) {
                    mx = max(abs(e.x - bb.x), mx);
                }
            }
        }

        //몸에 박음
        if (mx != -1) {
            die -= mx;
            break;
        }

        //벽에 박음
        if (abs(v[i].x) > l || abs(v[i].y) > l) {
            if (v[i].x == v[i - 1].x) die -= (abs(l - abs(v[i].y)) - 1);
            else die -= (abs(l - abs(v[i].x)) - 1);
            break;
        }
    }

    cout << die;
    return 0;
}
