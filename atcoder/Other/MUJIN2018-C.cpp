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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+2, vector<int>(m+2, 0)),
                        v2(n+2, vector<int>(m+2, 0)),
                        v3(n+2, vector<int>(m+2, 0));
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j) {
            if(s[j-1] == '.') v[i][j] = 1;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(v[j][i]){
                if(v2[j-1][i]){
                    v2[j][i] = v2[j-1][i];
                }else {
                    for (int k = j+1; k <= n; ++k) {
                        if(v[k][i]) v2[j][i]++;
                        else break;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(v[i][j]){
                if(v3[i][j-1]){
                    v3[i][j] = v3[i][j-1];
                }else {
                    for (int k = j+1; k <= m; ++k) {
                        if(v[i][k]) v3[i][j]++;
                        else break;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans += v2[i][j] * v3[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}
