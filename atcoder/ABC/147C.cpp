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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        G[i].resize(a);
        for (int j = 0; j < a; ++j) {
            cin >> G[i][j].first >> G[i][j].second;
            G[i][j].first--;
        }
    }
    int ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
        int ok = 1;
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                for (auto &&k : G[j]) {
                    if(((i >> k.first) & 1) != k.second){
                        ok = 0;
                    }
                }
            }
        }
        if(ok) ans = max(ans, __builtin_popcount(i));
    }
    cout << ans << "\n";
    return 0;
}