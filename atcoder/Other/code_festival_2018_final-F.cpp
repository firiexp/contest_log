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
    int n, k;
    cin >> n >> k;
    multiset<int> d1, d2;
    for (int i = 0; i < k; ++i) {
        d1.emplace(INF<int>);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int t, a;
        scanf("%d %d", &t, &a);
        ans += a;
        if(t == 0){
            d1.emplace(a);
            if(d1.size() > k) {
                ans -= *(d1.begin());
                d1.erase(d1.begin());
            } else {
                d2.erase(--d2.end());
            }
        }else {
            d2.emplace(a);
            if(d2.size() > k) {
                ans -= *(d2.begin());
                d2.erase(d2.begin());
            } else {
                d1.erase(--d1.end());
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
