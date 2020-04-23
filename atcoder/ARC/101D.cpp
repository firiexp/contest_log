#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
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
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%li", &i);
    int ok = 0, ng = INF<int>;
    ll s = (ll)n*(n+1)/2;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        vector<int> u(n+1);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            u[i+1] = u[i] + (v[i] >= mid ? 1 : -1);
            m = min(m, u[i+1]);
        }
        ll a = 0;
        BIT<int> b(n+1);
        for (auto &&i : u) {
            a += b.sum(i-m);
            b.add(i-m, 1);
        }
        if(2*a >= s) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}
