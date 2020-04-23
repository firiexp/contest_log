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


int main() {
    int n, r;
    cin >> n >> r;
    vector<int> xs{0, 1000010}, ys{0, 1000010}, zs{0, 1000010};
    using P = array<int, 6>;
    vector<array<int, 6>> v;

    for (int i = 0; i < n; ++i) {
        int a, b, c, d, e, f;
        scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
        v.emplace_back(P{a, b, c, d, e, f});
        xs.emplace_back(a); ys.emplace_back(b); zs.emplace_back(c);
        xs.emplace_back(d); ys.emplace_back(e); zs.emplace_back(f);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    sort(zs.begin(), zs.end());
    zs.erase(unique(zs.begin(), zs.end()), zs.end());
    auto zx = [&xs](int i){ return lower_bound(xs.begin(),xs.end(), i) - xs.begin(); };
    auto zy = [&ys](int i){ return lower_bound(ys.begin(),ys.end(), i) - ys.begin(); };
    auto zz = [&zs](int i){ return lower_bound(zs.begin(),zs.end(), i) - zs.begin(); };
    auto G = make_v(xs.size(), ys.size(), zs.size(), 0);
    for (int i = 0; i < n; ++i) {
        auto A = v[i];
        A[0] = zx(A[0]); A[1] = zy(A[1]); A[2] = zz(A[2]);
        A[3] = zx(A[3]); A[4] = zy(A[4]); A[5] = zz(A[5]);
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    if((j+k+l)&1) G[A[3*j]][A[3*k+1]][A[3*l+2]]--;
                    else G[A[3*j]][A[3*k+1]][A[3*l+2]]++;
                }
            }
        }
    }
    for (int i = 1; i < xs.size(); ++i) {
        for (int j = 0; j < ys.size(); ++j) {
            for (int k = 0; k < zs.size(); ++k) {
                G[i][j][k] += G[i-1][j][k];
            }
        }
    }
    for (int i = 0; i < xs.size(); ++i) {
        for (int j = 1; j < ys.size(); ++j) {
            for (int k = 0; k < zs.size(); ++k) {
                G[i][j][k] += G[i][j-1][k];
            }
        }
    }
    for (int i = 0; i < xs.size(); ++i) {
        for (int j = 0; j < ys.size(); ++j) {
            for (int k = 1; k < zs.size(); ++k) {
                G[i][j][k] += G[i][j][k-1];
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i+1 < xs.size(); ++i) {
        for (int j = 0; j+1 < ys.size(); ++j) {
            for (int k = 0; k+1 < zs.size(); ++k) {
                if(G[i][j][k] >= r){
                    ans += (ll)(xs[i+1]-xs[i])*(ys[j+1]-ys[j])*(zs[k+1]-zs[k]);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}