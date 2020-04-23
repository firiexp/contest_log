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
    int n, c;
    cin >> n >> c;
    int ans = INF<int>;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            int p = 0;
            if(i != j){
                for (int k = 0; k < n; ++k) {
                    if(k%2) p += c * (v[k] != i);
                    else p += c * (v[k] != j);
                }
                ans = min(ans, p);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
