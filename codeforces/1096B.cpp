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

static const int MOD = 998244353;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n; string s;
    cin >> n >> s;
    using P = array<int, 26>;
    vector<P> ls(n+1), rs(n+1);
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < 26; ++j) {
            ls[i+1][j] = ls[i][j] + (s[i]-'a' == j);
            cnt += (ls[i+1][j] != 0);
        }
        ans1 += cnt == 1;
    }
    for (int i = n-1; i >= 0; --i) {
        int cnt = 0;
        for (int j = 0; j < 26; ++j) {
            rs[i][j] = rs[i+1][j] + (s[i]-'a' == j);
            cnt += (rs[i][j] != 0);
        }
        ans2 += cnt == 1;
    }
    cout << (ans1 + ans2 + (s.front() == s.back() ? ans1*ans2 : 0) + 1) % MOD << "\n";
    return 0;
}