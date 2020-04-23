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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }


int main() {
    int k;
    cin >> k;
    vector<ll> ans;
    for (int len = 1; len <= 10; ++len) {
        string s;
        for (int i = 1; i < 10; ++i) {
            s += char('0'+i);
            auto dfs = [&](int x, auto &&f) -> void {
                if(!x){
                    ans.emplace_back(stoll(s));
                }else {
                    for (int i = -1; i <= 1; ++i) {
                        if(isdigit(s.back()+i)) {
                            s += char(s.back()+i);
                            f(x-1, f);
                            s.pop_back();
                        }
                    }
                }
            };
            dfs(len-1, dfs);
            s.pop_back();
        }


    }
    sort(ans.begin(),ans.end());
    cout << ans[k-1] << "\n";
    return 0;
}