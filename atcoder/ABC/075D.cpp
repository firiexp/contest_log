#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;
using P = pair<int, int>;
int main() {
    int n, k;
    cin >> n >> k;
    vector<P> v;
    map<int, int> X, Y, Xi, Yi;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
        X[x]++;
        Y[y]++;
    }
    {
        int p = 0, q = 0;
        for (auto &&t : X) {
            t.second = p++;
            Xi[t.second] = t.first;
        }
        for (auto &&t : Y) {
            t.second = q++;
            Yi[t.second] = t.first;
        }
    }
    vector<vector<int>> v2(n+2, vector<int>(n+2, 0));
    for (auto &&p : v) {
        v2[X[p.first]+1][Y[p.second]+1]++;
    }
    for (int i = 0; i < n+2; ++i) {
        for (int j = 1; j < n+2; ++j) {
            v2[i][j] += v2[i][j-1];
        }
    }
    for (int i = 1; i < n+2; ++i) {
        for (int j = 0; j < n+2; ++j) {
            v2[i][j] += v2[i-1][j];
        }
    }
    ll ans = numeric_limits<ll>::max();
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            for (int i2 = i+1; i2 < n+1; ++i2) {
                for (int j2 = j+1; j2 < n+1; ++j2) {
                    if(v2[i2][j2]-v2[i][j2]-v2[i2][j]+v2[i][j] >= k){
                        ans = min(ans, (ll)(Xi[i2-1]-Xi[i])*(Yi[j2-1]-Yi[j]));
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
