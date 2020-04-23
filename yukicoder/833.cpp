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
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    BIT<ll> S(n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        S.add(i, v[i]);
    }
    for (int i = 0; i <= n; ++i) {
        s.insert(i);
    }
    for (int i = 0; i < q; ++i) {
        int Q;
        scanf("%d", &Q);
        int x;
        scanf("%d", &x);
        x--;
        if(Q == 1){
            s.erase(x+1);
        }else if(Q == 2){
            s.insert(x+1);
        }else if(Q == 3){
            S.add(x, 1);
        }else {
            int lb = *(--s.upper_bound(x)), ub = *s.upper_bound(x);
            printf("%lld\n", S.sum(ub-1)-S.sum(lb-1));
        }
    }
    return 0;
}