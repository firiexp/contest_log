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
    vector<int> v(n);
    vector<pair<int, int>> u;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            if(s[j] == 'o') v[i]++;
            else if(i < j && s[j] == '-') u.emplace_back(i, j);
        }
    }

    int ans = INF<int>;
    for (int i = 0; i < (1<<u.size()); ++i) {
        vector<int> v1 = v;
        for (int j = 0; j < u.size(); ++j) {
            v1[(i & (1 << j) ? u[j].first : u[j].second)]++;
        }
        auto v2 = v1;
        sort(v1.begin(), v1.end());
        v1.erase(unique(v1.begin(), v1.end()), v1.end());
        ans = min(ans, static_cast<int>(v1.size())-static_cast<int>(lower_bound(v1.begin(), v1.end(), v2[0]) - v1.begin()));
    }
    cout << ans << "\n";
    return 0;
}
