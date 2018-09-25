#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> v(n, b);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        for (int j = l-1; j <= r-1; ++j) {
            v[j] = a;
        }
    }
    cout << accumulate(v.begin(), v.end(), 0) << "\n";
    return 0;
}
