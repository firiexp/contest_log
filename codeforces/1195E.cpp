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

template<class G>
class SWAG {
    using T = typename G::T;
    vector<T> in, out, insum, outsum;
public:
    SWAG() : in(0), out(0), insum(1, G::e()), outsum(1, G::e()) {}

    void push(const T& v){
        insum.push_back(G::f(insum.back(), v));
        in.push_back(v);
    }

    void pop(){
        if(out.empty()){
            do {
                out.emplace_back(in.back());
                outsum.emplace_back(G::f(in.back(), outsum.back()));
                in.pop_back(); insum.pop_back();
            }while(!in.empty());
        }
        out.pop_back(); outsum.pop_back();
    }

    T fold(){
        return G::f(outsum.back(), insum.back());
    }
};

struct Monoid {
    using T = int;
    static inline T f(T a, T b) { return min(a, b); }
    static inline T e() { return INF<int>; }
};

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    auto v = make_v(n, m, 0);
    auto ans = make_v(n, m, 0);
    ll x, y; int g0, z;
    cin >> g0 >> x >> y >> z;
    vector<int> g(n*m);
    g[0] = g0;
    for (int i = 1; i < n*m; ++i) {
        g[i] = (g[i-1]*x+y)%z;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            v[i][j] = g[i*m+j];
        }
    }
    for (int i = 0; i < n; ++i) {
        SWAG<Monoid> Q;
        for (int j = 0; j < m; ++j) {
            Q.push(v[i][j]);
            if(j+1 >= b) {
                ans[i][j-b+1] = Q.fold();
                Q.pop();
            }
        }
    }
    ll anss = 0;
    for (int i = 0; i < m-b+1; ++i) {
        SWAG<Monoid> Q;
        for (int j = 0; j < n; ++j) {
            Q.push(ans[j][i]);
            if(j >= a-1){
                anss += Q.fold();
                Q.pop();
            }
        }
    }
    cout << anss << "\n";
    return 0;
}