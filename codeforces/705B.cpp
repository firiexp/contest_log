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
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        s += k-1;
        puts(s % 2 ? "1" : "2");
    }
    return 0;
}
