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
    int n;
    cin >> n;
    using P = pair<int, int>;
    vector<P> v;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        v.emplace_back(a%b, b);
    }
    ll ans = 0, k = 0;
    for (int i = n-1; i >= 0; --i) {
        k = ans % v[i].second;
        if((k+v[i].first)%v[i].second){
            ans += v[i].second - (k+v[i].first)%v[i].second;
        }
    }
    cout << ans << "\n";
    return 0;
}
