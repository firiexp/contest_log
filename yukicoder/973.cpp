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

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template<class T, class U>
vector<T> make_v(U size, const T &init) { return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) {
    return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...));
}

template<class T>
void chmin(T &a, const T &b) { a = (a < b ? a : b); }

template<class T>
void chmax(T &a, const T &b) { a = (a > b ? a : b); }

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        ll sum = 0, cnt = 0;
        for (int j = i; j < n; j++) {
            sum += v[j];
            if (sum > x)break;
            cnt++;
        }
        l[i] = cnt;
        sum = 0, cnt = 0;
        for (int j = i; j >= 0; j--) {
            sum += v[j];
            if (sum > x) break;
            cnt++;
        }
        r[i] = cnt;
    }
    auto dp1 = make_v(n+1, n+1, 0), dp2 = dp1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n-i+1; ++j) {
            int a = j, b = j+i-1;
            if(dp2[b][i-1]-dp2[b][max(0, i-1-l[a])] != min(i-1, l[a])){
                dp1[a][i] = dp1[a][i-1]+1;
                dp2[b][i] = dp2[b][i-1]+1;
                continue;
            }
            if(dp1[a][i-1]-dp1[a][max(0, i-1-r[b])] != min(i-1, r[b])){
                dp1[a][i] = dp1[a][i-1]+1;
                dp2[b][i] = dp2[b][i-1]+1;
                continue;
            }
            dp1[a][i] = dp1[a][i-1];
            dp2[b][i] = dp2[b][i-1];
        }
    }
    puts(dp1[0][n] - dp1[0][n-1] ? "A" : "B");
    return 0;
}