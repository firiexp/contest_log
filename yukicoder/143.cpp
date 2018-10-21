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
    int k, n, f;
    cin >> k >> n >> f;
    k *= n;
    for (int i = 0; i < f; ++i) {
        int p;
        cin >> p;
        k -= p;
    }
    cout << (k < 0 ? -1 : k) << "\n";
    return 0;
}
