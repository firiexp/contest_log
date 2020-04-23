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
    int t;
    cin >> t;
    while(t--){
        int r, c, k;
        cin >> r >> c >> k;
        auto v = make_v(r, c, 0);
        auto ans = make_v(r, c, 'a');

        int cnt = 0;
        for (int i = 0; i < r; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < c; ++j) {
                v[i][j] = (s[j] == 'R');
                cnt += v[i][j];
            }
        }
        vector<int> w(k);
        for (int i = 0; i < k; ++i) {
            w[i] = cnt/k+((cnt%k) > i);
        }
        vector<char> u;
        for (int i = 'a'; i <= 'z'; ++i) {
            u.emplace_back(i);
        }
        for (int i = 'A'; i <= 'Z'; ++i) {
            u.emplace_back(i);
        }
        for (int i = '0'; i <= '9'; ++i) {
            u.emplace_back(i);
        }
        int cntt = 0, cur = 0;
        for (int i = 0; i < r; ++i) {
            if(i%2){
                for (int j = 0; j < c; ++j) {
                    ans[i][j] = u[cur];
                    if(v[i][j]) cntt++;
                    if(cntt == w[cur]){
                        cur++;
                        cntt = 0;
                        if(cur == k){
                            cur--;
                            cntt = -INF<int>;
                        }
                    }
                }
            }else {
                for (int j = c - 1; j >= 0; --j) {
                    ans[i][j] = u[cur];
                    if(v[i][j]) cntt++;
                    if(cntt == w[cur]){
                        cur++;
                        cntt = 0;
                        if(cur == k){
                            cur--;
                            cntt = -INF<int>;
                        }

                    }
                }
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                printf("%c", ans[i][j]);
            }
            puts("");
        }
    }

    return 0;
}