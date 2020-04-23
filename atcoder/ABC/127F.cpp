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
        for (++k; k < bit.size(); k  += (k & -k)) bit[k] += x;
    }
};

int main() {
    int q;
    cin >> q;
    set<int> s;

    vector<array<int, 3>> u(q);
    vector<int> z;
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        if(x == 1){
            int a, b;
            scanf("%d %d", &a, &b);
            u[i] = {x, a, b};
            z.emplace_back(a);
        }else {
            u[i] = {x};
        }
    }
    z.emplace_back(-INF<int>);
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    auto f = [&z](int i){return lower_bound(z.begin(),z.end(), i) - z.begin(); };
    int m = z.size();
    BIT<ll> S(m);
    BIT<ll> T(m);
    int cnt = 0;
    ll v = 0, vv = 0;
    for (int i = 0; i < q; ++i) {
        if(u[i][0] == 1){
            v += u[i][2];
            vv += u[i][1];
            S.add(f(u[i][1]), 1);
            T.add(f(u[i][1]), u[i][1]);
            cnt++;
        }else {
            int ng = -1, ok = m+1;
            while(ok-ng > 1){
                int mid = (ok+ng)/2;
                if(S.sum(mid) >= (cnt+1)/2) ok = mid;
                else ng = mid;
            }
            printf("%i %lli\n", z[ok], (2*S.sum(ok-1)-cnt)*z[ok] +vv-2*T.sum(ok-1)+v);
        }
    }
    return 0;
}