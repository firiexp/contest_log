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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> v(c, vector<int>(c, 0));
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> m(3, vector<int>(c, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            m[(i+j)%3][x-1]++;
        }
    }
    ll ans = INF<ll>;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c; ++j) {
            if(i == j) continue;
            for (int k = 0; k < c; ++k) {
                if(j == k) continue;
                if(i == k) continue;
                ll p = 0;
                for (int l = 0; l < c; ++l) {
                    p += v[l][i]*m[0][l] + v[l][j]*m[1][l] + v[l][k]*m[2][l];
                }
                ans = min(ans, p);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
