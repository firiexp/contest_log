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

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> v(n);
    for (auto &&j : v) scanf("%d", &j);
    if(m == 2){
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; ++i) {
            if(i&1) {
                if(v[i] == 1) ans1++;
                else ans2++;
            } else {
                if(v[i] == 1) ans2++;
                else ans1++;
            }
        }
        cout << min(ans1, ans2) << "\n";
        return 0;
    }
    vector<pair<int, int>> u;
    u.emplace_back(v[0], 1);
    for (int i = 1; i < n; ++i) {
        if(u.back().first == v[i]) u.back().second++;
        else u.emplace_back(v[i], 1);
    }
    int ans = 0;
    for (int i = 0; i < u.size(); ++i) {
        ans += u[i].second/2;
    }
    cout << ans << "\n";
    return 0;
}