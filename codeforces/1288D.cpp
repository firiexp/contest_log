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
    int n, m;
    cin >> n >> m;
    auto v = make_v(n, m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &v[i][j]);
        }
    }
    int ok = -1, ng = INF<int>;
    int ans1 = 1, ans2 = 1;
    array<int, 256> ar{};
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        fill(ar.begin(),ar.end(), -1);
        for (int i = 0; i < n; ++i) {
            int val = 0;
            for (int j = 0; j < m; ++j) {
                if(mid <= v[i][j]){
                    val += 1 << j;
                }
            }
            ar[val] = i;
        }
        int good = 0;
        for (int i = 0; i < (1 << m); ++i) {
            if(ar[i] == -1) continue;
            for (int j = 0; j < (1 << m); ++j) {
                if(ar[j] == -1 || (i|j) != (1 << m)-1) continue;
                good = 1;
                ans1 = ar[i]+1; ans2 = ar[j]+1;
            }
        }
        (good ? ok : ng) = mid;
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}