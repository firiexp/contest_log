#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;
using P = pair<int, int>;
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
    int n, m;
    cin >> n >> m;

    vector<P> v(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[i] = make_pair(a, b+1);
    }
    sort(v.begin(), v.end(), [](P a, P b){ return a.second - a.first < b.second - b.first; });
    BIT<int> bit(m+3); int cur = 0;
    for (int k = 1; k <= m; ++k) {
        while (cur != n && v[cur].second-v[cur].first <= k){
            bit.add(v[cur].first, 1); bit.add(v[cur].second, -1);
            cur++;
        }
        int ans = n-cur;
        for (int i = k; i <= m; i += k) {
            ans += bit.sum(i);
        }
        cout << ans << "\n";
    }
    return 0;
}
