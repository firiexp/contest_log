#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

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
    vector<int> v(n);
    BIT<int> bit(n+1);
    for (auto &&i : v) scanf("%d", &i);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += bit.sum(n)-bit.sum(v[i]);
        bit.add(v[i], 1);
    }
    cout << ans << "\n";
    return 0;
}
