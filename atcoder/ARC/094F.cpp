#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 998244353;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

int main() {
    string s;
    cin >> s;
    int n = static_cast<int>(s.size());
    array<int, 3> cnt{}; int p = 0;
    for (int i = 0; i < n; ++i) {
        cnt[s[i]-'a']++;
        if(i && (s[i] == s[i-1])) p++;
    }
    if((cnt[0] == 0) + (cnt[1] == 0)+(cnt[2] == 0) == 2){
        puts("1");
        return 0;
    }else if(s.size() == 3){
        stack<string> q;
        map<string, int> m;
        q.emplace(s);
        while(!q.empty()){
            string w = q.top(); q.pop();
            m[w]++;
            for (int i = 0; i < 2; ++i) {
                if(w[i] != w[i+1]){
                    for (int j = 0; j < 3; ++j) {
                        if(w[i] != 'a'+j && w[i+1] != 'a'+j) {
                            string t = w;
                            t[i] = t[i+1] = static_cast<char>('a'+j);
                            if(!m[t]) q.emplace(t);
                        }
                    }
                }
            }
        }
        cout << m.size() << "\n";
        return 0;
    }
    auto dp = make_v(n+1, 3, 3, 2, 0);
    for (int i = 0; i < 3; ++i) dp[1][i][i][0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    (dp[i+1][(j+l)%3][l][k == l] += dp[i][j][k][0]) %= MOD;
                    (dp[i+1][(j+l)%3][l][1] += dp[i][j][k][1]) %= MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        (ans += dp[n][(cnt[1]+cnt[2]*2)%3][i][1]) %= MOD;
    }
    cout << ans + (p == 0) << "\n";
    return 0;
}
