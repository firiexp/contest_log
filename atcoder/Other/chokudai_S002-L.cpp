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

    T sum(int k) {
        T ret = 0;
        for (++k; k > 0; k -= (k & -k)) ret = max(ret, bit[k]);
        return ret;
    }

    void add(int k, T x){
        for (++k; k < bit.size(); k  += (k & -k)) bit[k] = max(bit[k], x);
    }
};

int main() {
    int n;
    cin >> n;
    using P = pair<int, int>;
    vector<pair<int, int>> v(n);
    vector<int> z(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
        if(v[i].first > v[i].second) swap(v[i].first, v[i].second);
        z[i] = v[i].second;
        v[i].second *= -1;
    }
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    auto f = [&z](int x){return lower_bound(z.begin(),z.end(), x) - z.begin();};
    int m = z.size();
    BIT<int> b(m);
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i) {
        b.add(f(-v[i].second), b.sum(f(-v[i].second)-1) + 1);
    }
    cout << b.sum(m-1) << "\n";
    return 0;
}