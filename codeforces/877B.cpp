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
    string s;
    cin >> s;
    int n = s.size();
    auto dp = make_v(n+1, 4, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            chmax(dp[i+1][j], dp[i][j]);
        }
        if(s[i] == 'a'){
            chmax(dp[i+1][1], dp[i][0]+1);
            chmax(dp[i+1][1], dp[i][1]+1);
            chmax(dp[i+1][3], dp[i][2]+1);
            chmax(dp[i+1][3], dp[i][3]+1);
        }else {
            chmax(dp[i+1][2], dp[i][1]+1);
            chmax(dp[i+1][2], dp[i][2]+1);
        }
    }
    cout << *max_element(dp.back().begin(),dp.back().end()) << "\n";
    return 0;
}