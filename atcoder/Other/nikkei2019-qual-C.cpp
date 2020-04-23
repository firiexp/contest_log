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

bool f(pair<int, int> a, pair<int, int> b){

}


int main() {
    int n;
    cin >> n;
    vector<ll> v;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ans -= b;
        v.emplace_back(a+b);
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        if(i%2 == 0) ans += v[i];
    }
    cout << ans << "\n";
    return 0;
}
