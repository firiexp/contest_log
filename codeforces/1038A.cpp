#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    using P = array<int, 26>;
    P x{};
    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        x[s[i]-'A']++;
    }
    for (int i = 0; i < k; ++i) {
        ans = min(ans, x[i]);
    }
    cout << ans*k << "\n";
    return 0;
}