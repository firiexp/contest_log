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
    int n, k;
    cin >> n >> k;
    vector<long double> v;
    for (int i = 0; i < n; ++i) {
        long double x;
        cin >> x;
        v.emplace_back(x);
    }
    sort(v.begin(), v.end(), greater<>());
    long double x = 1.0/2.0;
    long double ans = 0.0;
    for (int i = 0; i < k; ++i) {
        ans += v[i]*x;
        x /= 2.0;
    }
    cout << setprecision(20) << ans << "\n";
    return 0;
}
