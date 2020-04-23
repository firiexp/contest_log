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
    ll k;
    cin >> k;
    vector<ll> ans(50);
    for (int i = 0; i < 50; ++i) {
        ans[i] = i+k/50;
    }
    for (int i = 0; i < k%50; ++i) {
        for (int j = 0; j < 50; ++j) {
            if(i == j) ans[j] += 50;
            else ans[j]--;
        }
    }
    cout << 50 << "\n";
    for (int i = 0; i < 50; ++i) {
        if(i) cout << " ";
        cout << ans[i];
    }

    return 0;
}
