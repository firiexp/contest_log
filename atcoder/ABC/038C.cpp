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
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> v(n);
    for (auto &&j : v) scanf("%d", &j);
    v.emplace_back(-1);
    for (int i = 0; i < n; ++i) {
        int k = 1;
        for (int j = i+1; j < n; ++j) {
            if(v[j] > v[j-1]) k++;
            else break;
        }
        ans += (ll)k*(k+1)/2;
        i = i+k-1;
    }
    cout << ans << "\n";
    return 0;
}
