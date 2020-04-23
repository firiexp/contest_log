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
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (auto &&i : w) scanf("%d", &i);
    int a = min(n, 16), b = n-a;
    map<int, int> v2;
    for (int i = 0; i < (1<<b); ++i) {
        int s = 0;
        for (int j = 0; j < b; ++j) {
            if(i & (1 << j)) s += w[j+a];
        }
        v2[s]++;
    }
    ll ans = 0;
    for (int i = 0; i < (1<<a); ++i) {
        int s = 0;
        for (int j = 0; j < a; ++j) {
            if(i & (1 << j)) s += w[j];
        }
        if(v2.count(x-s))ans += v2[x-s];
    }
    cout << ans << "\n";
    return 0;
}