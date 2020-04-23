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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    vector<ll> s(n+1);
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i] + v[i];
    }
    auto rec = [&](int l, int r, auto &&f) -> int {
        auto mid = lower_bound(v.begin()+l,v.begin()+r, (s[r]-s[l]+r-l-1)/(r-l)) - v.begin();
        if(mid == l || mid == r) return 1;
        if(f(l, mid, f) && f(mid, r, f)) return 0;
        else return 1;
    };
    puts(rec(0, n, rec) ? "First" : "Second");
    return 0;
}