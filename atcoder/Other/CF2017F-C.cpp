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

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        m[d]++;
        if(m[d] >= 3 || d == 0) {
            puts("0");
            return 0;
        }
    }
    vector<int> a, b;
    a.emplace_back(0);
    int ans1 = INF<int>;
    for (auto &&i : m) {
        if(i.second == 2) a.emplace_back(i.first), a.emplace_back(24-i.first);
        else b.emplace_back(i.first);
        ans1 = min(ans1, i.first);
    }
    int ans = 0;
    auto k = b.size();
    vector<int> c(a.size()+k);
    for (int i = 0; i < a.size(); ++i) c[i] = a[i];
    for (int i = 0; i < (1 << k); ++i) {
        for (int j = 0; j < k; ++j) {
            if (i & (1<<j)) {
                c[a.size()+j] = (24 - b[j]);
            } else {
                c[a.size()+j] = b[j];
            }
        }
        int p = INF<int>;
        for (int l = 0; l < c.size(); ++l) {
            for (int j = l+1; j < c.size(); ++j) {
                p = min(p, abs(c[l]-c[j]));
            }
        }
        ans = max(ans, p);
    }
    cout << min(ans, ans1) << "\n";
    return 0;
}
