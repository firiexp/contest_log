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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    auto dp = make_v(n+2, 26, n+1);
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            if(s[i]-'a' == j){
                dp[i][j] = i+1;
            }else {
                dp[i][j] = dp[i+1][j];
            }
        }
    }

    auto dp2 = make_v(251, 251, 251, n+1);
    dp2[0][0][0] = 0;
    int cur1 = 0, cur2 = 0, cur3 = 0;
    string a, b, c;
    for (int i = 0; i < q; ++i) {
        char p;
        cin >> p;
        if(p == '+'){
            char pp, ppp;
            cin >> pp >> ppp;
            if(pp == '1'){
                cur1++;
                a += ppp;
                for (int j = 0; j <= cur2; ++j) {
                    for (int k = 0; k <= cur3; ++k) {
                        if(cur1) chmin(dp2[cur1][j][k], dp[dp2[cur1-1][j][k]][a[cur1-1]-'a']);
                        if(j) chmin(dp2[cur1][j][k], dp[dp2[cur1][j-1][k]][b[j-1]-'a']);
                        if(k) chmin(dp2[cur1][j][k], dp[dp2[cur1][j][k-1]][c[k-1]-'a']);
                    }
                }
            }else if(pp == '2'){
                cur2++;
                b += ppp;
                for (int j = 0; j <= cur1; ++j) {
                    for (int k = 0; k <= cur3; ++k) {
                        if(j) chmin(dp2[j][cur2][k], dp[dp2[j-1][cur2][k]][a[j-1]-'a']);
                        if(cur2) chmin(dp2[j][cur2][k], dp[dp2[j][cur2-1][k]][b[cur2-1]-'a']);
                        if(k) chmin(dp2[j][cur2][k], dp[dp2[j][cur2][k-1]][c[k-1]-'a']);
                    }
                }
            }else {
                cur3++;
                c += ppp;
                for (int j = 0; j <= cur1; ++j) {
                    for (int k = 0; k <= cur2; ++k) {
                        if(j) chmin(dp2[j][k][cur3], dp[dp2[j-1][k][cur3]][a[j-1]-'a']);
                        if(k) chmin(dp2[j][k][cur3], dp[dp2[j][k-1][cur3]][b[k-1]-'a']);
                        if(cur3) chmin(dp2[j][k][cur3], dp[dp2[j][k][cur3-1]][c[cur3-1]-'a']);
                    }
                }
            }
        } else {
            char pp;
            cin >> pp;
            if(pp == '1'){
                for (int j = 0; j <= cur2; ++j) {
                    for (int k = 0; k <= cur3; ++k) {
                        dp2[cur1][j][k] = n+1;
                    }
                }
                cur1--;
                a.pop_back();
            }else if(pp == '2'){
                for (int j = 0; j <= cur1; ++j) {
                    for (int k = 0; k <= cur3; ++k) {
                        dp2[j][cur2][k] = n+1;
                    }
                }
                cur2--;
                b.pop_back();
            }else {
                for (int j = 0; j <= cur1; ++j) {
                    for (int k = 0; k <= cur2; ++k) {
                        dp2[j][k][cur3] = n+1;
                    }
                }
                cur3--;
                c.pop_back();
            }
        }
        if(dp2[cur1][cur2][cur3] != n+1){
            puts("YES");
        }else {
            puts("NO");
        }
    }
    return 0;
}