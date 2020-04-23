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

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> u = {-1,2,5,5,4,5,6,3,7,6};
    vector<pair<int, int>> w;
    for (int i = 0; i < m; ++i) {
        w.emplace_back(u[v[i]], -v[i]);
    }
    sort(w.begin(), w.end());
    for (int i = 0; i < m; ++i) {
        w[i].second = -w[i].second;
    }
    vector<pair<int, int>> dp(10001);
    dp[0] = make_pair(1, 0);
    for (int i = 0; i <= 10000; ++i) {
        for (int j = 0; j < m; ++j) {
            if(i-w[j].first >= 0){
                dp[i] = max(dp[i],
                            make_pair(dp[i-w[j].first].first+1, w[j].second));
            }
        }
    }
    string ans;
    while(n > 0){
        ans += (dp[n].second + '0');
        n -= u[dp[n].second];
    }
    sort(ans.begin(), ans.end(), greater<>());
    cout << ans << "\n";
    return 0;
}
