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
    int n;
    cin >> n;
    vector<int> v(2*n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        v[n+i] = v[i];
    }
    vector<ll> S(2*n+1);
    for (int i = 0; i < 2*n; ++i) {
        S[i+1] = S[i] + v[i];
    }
    auto f = [&](int i, ll X){
        auto next = lower_bound(S.begin()+i+1, S.begin()+i+1+n, S[i]+X);
        if(next == S.begin()+i+1+n) return false;
        auto nextnext = lower_bound(S.begin()+i+1, S.begin()+i+1+n, *next+X);
        if(nextnext == S.begin()+i+1+n) return false;
        return S[i+n] - *nextnext >= X;
    };
    ll ok = 0, ng = S[n]/3+2;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        int okk = 0;
        for (int i = 0; i < n; ++i) {
            if(f(i, mid)) {
                okk = 1;
                break;
            }
        }
        if(okk) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}