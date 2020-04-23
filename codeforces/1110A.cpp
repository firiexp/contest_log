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

int main() {
    int b, k;
    cin >> b >> k;
    vector<int> v(k);
    for (auto &&i : v) scanf("%d", &i);
    reverse(v.begin(), v.end());
    int i = 1, p = 0;
    for (int j = 0; j < k; ++j) {
        (p += v[j]*i) %= 2;
        (i *= b) %= 2;
    }
    puts(p%2 ? "odd" : "even");
    return 0;
}
