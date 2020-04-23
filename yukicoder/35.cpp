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
    int n, ans = 0, ans2 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        string s;
        cin >> k >> s;
        ans += max(0, (int)s.length()-12*k/1000), ans2 += s.length()-max(0, (int)s.length()-12*k/1000);
    }
    printf("%d %d\n", ans2, ans);
    return 0;
}
