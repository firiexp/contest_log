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

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    if(n == 1){
        puts("1");
        return 0;
    }
    int ans = INF<int>;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            int dx = x[i]-x[j], dy = y[i]-y[j];
            vector<int> cnt(n);
            int a = 0;
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < n; ++l) {
                    if(k == l) continue;
                    if(x[l]-x[k] == dx && y[l]-y[k] == dy) cnt[l]++;
                }
            }
            for (int k = 0; k < n; ++k) {
                if(!cnt[k]) a++;
            }
            ans = min(ans, a);
        }
    }
    cout << ans << "\n";
    return 0;
}