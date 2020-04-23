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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v((1<<n)+1), ans(1<<n);
    for(int i = 0; i < (1<<n); ++i) scanf("%d", &v[i]);
    vector<pair<int, int>> u(1<<n);
    auto f = [&](int a, int b){ return v[a] > v[b]; };
    for (int i = 0; i < (1<<n); ++i) {
        u[i] = make_pair(i, (1<<n));
        vector<int> x{u[i].first, u[i].second};
        for (int j = 0; j < n; ++j) {
            if(i&(1<<j)){
                int k = (i^(1<<j));
                x.emplace_back(u[k].first);
                x.emplace_back(u[k].second);
            }
        }
        sort(x.begin(), x.end(), f);
        x.erase(unique(x.begin(), x.end()), x.end());
        u[i] = make_pair(x[0], x[1]);
        ans[i] = v[u[i].first] + v[u[i].second];
    }
    for (int i = 1; i < (1 << n); ++i) {
        ans[i] = max(ans[i], ans[i-1]);
        cout << ans[i] << "\n";
    }
    return 0;
}
