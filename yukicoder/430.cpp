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
#include <chrono>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;

using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<map<string, int>> v(11);;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j+i <= n; ++j) {
            v[i][s.substr(j, i)]++;
        }
    }
    int m;
    cin >> m;
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        string t;
        cin >> t;
        ans += v[t.size()][t];
    }
    cout << ans << "\n";
    return 0;
}