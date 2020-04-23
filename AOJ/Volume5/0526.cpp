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
    int n, k;
    while (cin >> n >> k, n|k){
        vector<vector<int>> v(n, vector<int>(n, INF<int>));
        for (int i = 0; i < n; ++i) {
            v[i][i] = 0;
        }
        for (int i = 0; i < k; ++i) {
            int a;
            scanf("%d", &a);
            if(a == 0){
                int p, q;
                cin >> p >> q;
                cout << (v[p-1][q-1] != INF<int> ? v[p-1][q-1] : -1) << "\n";
            }else {
                int c, d, e;
                cin >> c >> d >> e;
                if(v[c-1][d-1] > e){
                    v[c-1][d-1] = e;
                    for (int l = 0; l < n; ++l) {
                        for (int m = l; m < n; ++m) {
                            v[m][l] = v[l][m] = min(v[l][m], e + min(v[l][c-1]+v[d-1][m], v[l][d-1]+v[c-1][m]));
                        }
                    }
                }
            }
        }
    }

    return 0;
}
