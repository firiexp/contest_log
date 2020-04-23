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
    int n, t;
    cin >> n >> t;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v1[i]);
    }
    int v = 0;
    v2[0] = -INF<int>;
    for (int i = n-1; i >= 1; --i) {
        v = max(v, v1[i]);
        v2[i-1] = v-v1[i-1];
    }
    sort(v2.begin(), v2.end(), greater<>());
    cout << (upper_bound(v2.begin(), v2.end(), v2[0], greater<>())-v2.begin())<< "\n";
    return 0;
}
