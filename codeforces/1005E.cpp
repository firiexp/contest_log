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

template<class T>
class BIT2D {
    vector<T> bit;
public:
    BIT2D(int n): bit(vector<T>(n + 1, 0)){}

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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    auto f = [&](int x) -> ll {
        ll ret = 0;
        BIT2D<int> S(2 * n + 1);
        vector<int> T(n+1);
        for (int i = 0; i < n; ++i) T[i+1] = T[i] + (v[i] <= x ? 1 : -1);
        int mn = *min_element(T.begin(),T.end());
        for (auto &&i : T) {
            ret += S.sum(i-mn);
            S.add(i-mn, 1);
        }
        return ret;
    };
    cout << f(m)-f(m-1) << "\n";
    return 0;
}