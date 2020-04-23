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

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> dpi(n+1, vector<int>(m+1, 0));
    auto dpo = dpi;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if((i && s[i-1] == 'I') ) dpi[i][j] = 1;
            if((j && t[j-1] == 'I')) dpi[i][j] = 1;
            if(i && dpi[i-1][j] > 0 && s[i-1] == 'O') chmax(dpo[i][j], dpi[i-1][j]+1);
            if(i && dpo[i-1][j] > 0 && s[i-1] == 'I') chmax(dpi[i][j], dpo[i-1][j]+1);
            if(j && dpi[i][j-1] > 0 && t[j-1] == 'O') chmax(dpo[i][j], dpi[i][j-1]+1);
            if(j && dpo[i][j-1] > 0 && t[j-1] == 'I') chmax(dpi[i][j], dpo[i][j-1]+1);
            ans = max(ans, dpi[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}