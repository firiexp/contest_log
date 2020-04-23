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

template<class T>
class BIT {
    vector<T> bit;
public:
    BIT(int n): bit(vector<T>(n+1, 0)){}

    T sum(int k){
        T ret = 0;
        for (++k; k > 0; k -= (k & -k)) ret += bit[k];
        return ret;
    }

    void add(int k, T x){
        for (; k < bit.size(); k  += (k & -k)) bit[k] += x;
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    BIT<ll> S(n+1), T(n+1);
    for (int i = 0; i < q; ++i) {
        int c;
        scanf("%d", &c);
        if(c == 0){
            ll s, t, x;
            scanf("%lld %lld %lld", &s, &t, &x);
            S.add(s, x);
            S.add(t+1, -x);
            T.add(s, -x*(s-1));
            T.add(t+1, x*t);
        }else {
            ll x, y;
            scanf("%lld %lld", &x, &y);
            printf("%lld\n", T.sum(y)-T.sum(x-1)+y*S.sum(y)-(x-1)*S.sum(x-1));
        }
    }
    return 0;
}
