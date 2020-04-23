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
    vector<ll> b(n);
    for (auto &&i : b) scanf("%lld", &i);
    vector<ll> p(n+1), q(n+1); // px+q;
    ll l = 1, r = 1e18;
    ll ans1 = 1, ans2 = 1e18;
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if(i & 1){
            p[i] = -p[i-1];
            q[i] = -q[i-1]+b[i-1];
        }else {
            p[i] = p[i-1];
            q[i] = q[i-1]-b[i-1];
        }
        if(p[i] > 0){
            ans1 = max(ans1, l-q[i]);
            ans2 = min(ans2, r-q[i]);
            if(ans1 > ans2) {
                puts("-1");
                return 0;
            }
        }else {
            ans1 = max(ans1, q[i]-r);
            ans2 = min(ans2, q[i]-l);
            if(ans1 > ans2) {
                puts("-1");
                return 0;
            }
        }
    }
    printf("%d\n", n+1);
    for (int i = 0; i < n+1; ++i) {
        printf("%lld\n", p[i]*ans1+q[i]);
    }
    return 0;
}