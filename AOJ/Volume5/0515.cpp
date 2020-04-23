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
    int a, b, n;
    while(cin >> a >> b, a|b){
        cin >> n;
        vector<vector<int>> dp(b, vector<int>(a, 0));
        map<pair<int, int>, int> m;
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            m[make_pair(x-1, y-1)]++;
        }
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < a; ++j) {
                if(m[make_pair(j, i)]) continue;
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
        cout << dp[b-1][a-1] << "\n";
    }

    return 0;
}
