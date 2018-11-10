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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n, m, u = 0, ma = 0, p = 0;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        u += k;
        ma = max(ma, k);
        v.emplace_back(k);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        p += ma - v[i];
    }
    cout  << (p >= m ?  ma  :ma + (m-p+n-1)/n) << " " << ma + m << "\n";
    return 0;
}
