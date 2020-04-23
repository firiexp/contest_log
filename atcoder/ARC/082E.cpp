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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }


int main() {
    ll n;
    cin >> n;
    vector<array<int, 2>> v(n);
    for (auto &&i : v) scanf("%d %d", &i[0], &i[1]);
    vector<ll> p2(n+1);
    p2[0] = 1;
    for (int i = 0; i < n; ++i) {
        p2[i+1] = p2[i]*2%MOD;
    }
    ll ans = (p2[n]+MOD-1-n-n*(n-1)/2) % MOD;
    auto checked = make_v(n, n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(!checked[i][j]){
                vector<int> u;
                u.emplace_back(i); u.emplace_back(j);
                for (int k = 0; k < n; ++k) {
                    if(k != i && k != j){
                        if((v[k][0]-v[i][0])*(v[j][1]-v[i][1]) ==
                            (v[k][1]-v[i][1])*(v[j][0]-v[i][0])) u.emplace_back(k);
                    }
                }
                for (auto &&l : u) {
                    for (auto &&k : u) {
                        checked[l][k] = 1;
                    }
                }
                int w = static_cast<int>(u.size());
                if(w >= 3) (ans += (MOD- p2[w]+w+w*(w-1)/2 + 1)) %=  MOD;
            }
        }
    }
    cout << (ans%MOD+MOD)%MOD << "\n";
    return 0;
}
