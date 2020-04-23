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
    int k;
    cin >> k;
    vector<vector<int>> v(k);
    map<int, pair<int, int>> m;
    vector<ll> sums(k); ll sum = 0;
    int sz = 0;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        sz += n;
        v[i].reserve(n);
        for (int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            sums[i] += x;
            sum += x;
            v[j].emplace_back(x);
            m[x] = {i, j};
        }
    }
    if(sum%k){
        puts("No");
        return 0;
    }

    return 0;
}