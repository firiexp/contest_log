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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int k = 1; k <= m; ++k) {
        for (int x = 0; x < n-1; ++x) {
            if(v[x]%k > v[x+1]%k) swap(v[x], v[x+1]);
        }
    }
    for (auto &&i : v) {
        printf("%d\n", i);
    }
    return 0;
}
