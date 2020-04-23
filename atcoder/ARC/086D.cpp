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
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    bool nega = false;
    ll p = 0, q = 0;
    for (int j = 0; j < n; ++j) {
        if(llabs(v[j]) > llabs(p)) p = v[j], q = j;
    }
    vector<ll> u = v;
    vector<pair<int, int>> ans;
    if(p < 0) {
        nega = true;
        for (int i = 0; i < n; ++i) {
            v[i] = -v[i];
        }
        q = n-1-q;
        reverse(v.begin(), v.end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 1 + (v[i] < 0); ++j) {
            if(nega) ans.emplace_back(n-q, n-i);
            else ans.emplace_back(q+1, i+1);
        }
        q = i;
    }
    cout << ans.size() << "\n";
    for (auto &&i : ans) {
        u[i.second-1] += u[i.first-1];
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
