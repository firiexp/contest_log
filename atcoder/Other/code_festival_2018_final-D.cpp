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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


int main() {
    int Q;
    cin >> Q;
    array<ll, 90001> l{}, m{};
    auto f = [](char c){ return (c > 'Z' ? c-'a'+26 : c-'A'); };
    auto f2 = [](int x){ return (x >= 26 ? char('a'+ x-26) : char('A'+x)); };
    auto v = make_v(52, 52, 52, 0);
    auto u = make_v(52, 52, 52, -1);
    for (int q = 0; q < Q; ++q) {
        string s;
        cin >> s;
        int n = s.size();
        if(n < 52){
            for (int i = 0; i < n; ++i) {
                for (int j = i+1; j < n; ++j) {
                    for (int k = j+1; k < n; ++k) {
                        int a = f(s[i]), b = f(s[j]), c = f(s[k]);
                        if(u[a][b][c] != q){
                            v[a][b][c]++;
                            u[a][b][c] = q;
                        }
                    }
                }
            }
        }else {
            l[0] = 0;
            for (int i = 0; i < n; ++i) {
                l[i+1] = (l[i] | (1LL << f(s[i])));
            }
            m[n] = 0;
            for (int i = n-1; i >= 0; --i) {
                m[i] = (m[i+1] | (1LL << f(s[i])));
            }
            for (int i = 1; i < n-1; ++i) {
                for (int j = 0; j < 52; ++j) {
                    for (int k = 0; k < 52; ++k) {
                        if((!(l[i] & (1LL << j))) || (!(m[i+1] & (1LL << k)))) continue;
                        int b = f(s[i]);
                        if(u[j][b][k] != q){
                            v[j][b][k]++;
                            u[j][b][k] = q;
                        }
                    }
                }
            }
        }
    }
    int ans = 0; string t;
    for (int i = 0; i < 52; ++i) {
        for (int j = 0; j < 52; ++j) {
            for (int k = 0; k < 52; ++k) {
                if(ans < v[i][j][k]){
                    ans = v[i][j][k];
                    t = string{f2(i), f2(j), f2(k)};
                }
            }
        }
    }
    cout << t << "\n";
    return 0;
}
