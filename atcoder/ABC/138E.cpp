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

vector<vector<int>> calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(26, -1));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    s += s;
    s += s;
    auto p = calcNext(s);
    ll ans = 0, cur = -1;
    for (auto &&i : t) {
        int curr = p[cur+1][i-'a'];
        if(curr == -1){
            puts("-1");
            return 0;
        }
        ans += curr-cur;
        cur = (curr)%n;
    }
    cout << ans << "\n";
    return 0;
}