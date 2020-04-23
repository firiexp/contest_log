#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    array<int, 4> ar{};
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &ar[i]);
    }
    string s;
    cin >> s;
    int ans = 0;
    for (auto &&i : s) {
        ans += ar[i-'1'];
    }
    cout << ans << "\n";
    return 0;
}
