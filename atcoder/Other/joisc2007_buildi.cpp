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
    vector<int> v(n, INF<int>);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        *lower_bound(v.begin(), v.end(), x) = x;
    }
    cout << lower_bound(v.begin(), v.end(), INF<int>) - v.begin() << "\n";
    return 0;
}
