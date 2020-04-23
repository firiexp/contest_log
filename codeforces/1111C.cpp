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
    int n, k; ll a, b;
    cin >> n >> k >> a >> b;
    vector<int> v(k);
    for (auto &&i : v) scanf("%d", &i), i--;
    sort(v.begin(),v.end());
    auto rec = [&](int l, int r, int Al, int Ar, auto &&f) -> ll {
        if(Al >= Ar) return a;
        if(r-l == 1) return b*(Ar-Al);
        int mid = l+(r-l)/2;
        int part = lower_bound(v.begin()+Al,v.begin()+Ar, mid) - v.begin();
        return min(b*(Ar-Al)*(r-l), f(l, mid, Al, part, f)+f(mid, r, part, Ar, f));
    };
    cout << rec(0, 1<<n, 0, k, rec) << "\n";
    return 0;
}