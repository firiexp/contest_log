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
    int n, l;
    string s;
    cin >> n >> l >> s;
    int k = 1, ans = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '+') k++;
        else k--;
        if(k > l) ans++, k = 1;
    }
    cout << ans << "\n";
    return 0;
}
