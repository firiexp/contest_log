#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int h, w;
    while(cin >> h >> w, h){
        map<int, int> a, b;
        for (int i = 0; i < h; ++i) {
            int x; cin >> x;
            a[x]++;
        }
        for (int i = 0; i < w; ++i) {
            int x; cin >> x;
            b[x]++;
        }
        for (auto &&j : b) {
            a[j.first] = max(j.second, a[j.first]);
        }
        int ans = 0;
        for (auto &&i : a) {
            ans += i.first*i.second;
        }
        cout << ans << "\n";
    }
    return 0;
}