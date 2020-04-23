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
    int n, k;
    cin >> n >> k;
    vector<int> v(n, INF<int>), c(n);
    v[0] = 0;
    for (auto &&i : c) scanf("%d", &i);
    for (int i = 0; i < n-1; ++i) {
        for (int j = 1; j <= k; ++j) {
            if(i+j < n) v[i+j] = min(v[i+j],v[i]+abs(c[i+j]-c[i]));
        }
    }
    cout << v[n-1] << "\n";
    return 0;
}
