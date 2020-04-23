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

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> v(n), u(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
        u[i] = {y, x};
    }
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
    for (int i = 0; i < n; ++i) {
        auto x = u[i];
        u[i] = {x.second, x.first};
    }
    puts(v == u ? "1" : "2");
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);

    }
    return 0;
}