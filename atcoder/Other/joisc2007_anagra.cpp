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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

array<int, 26> cnt{};

int main() {
    string s;
    cin >> s;
    ll a = 1, ans = 1;
    int n = s.size();
    for (int i = n-1; i >= 0; --i) {
        a /= ++cnt[s[i]-'A'];
        for (int j = 0; j < s[i]-'A'; ++j) {
            ans += a*cnt[j];
        }
        a *= n-i;
    }
    cout << ans << "\n";
    return 0;
}