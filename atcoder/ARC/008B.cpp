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
    int n, m;
    cin >> n >> m;
    vector<int> u(26), v(26);
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) u[s[i]-'A']++;
    cin >> s;
    for (int i = 0; i < m; ++i) v[s[i]-'A']++;
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        if(u[i] && !v[i]) {
            puts("-1");
            return 0;
        }
        if(!v[i]) continue;
        ans = max(ans, (u[i]+v[i]-1)/v[i]);
    }
    cout << ans << "\n";
    return 0;
}
