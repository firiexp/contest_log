#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
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
    int h, w;
    cin >> h >> w;
    auto v = make_v(h, w, 0);
    auto tate = v, yoko = v;
    vector<int> tatesize(w), yokosize(h);
    for (auto &&i : v) for (auto &&j : i) scanf("%d", &j);
    for (int i = 0; i < h; ++i) {
        vector<int> u(w);
        for (int j = 0; j < w; ++j) {
            u[j] = v[i][j];
        }
        sort(u.begin(), u.end());
        u.erase(unique(u.begin(), u.end()), u.end());
        yokosize[i] = u.size();
        for (int j = 0; j < w; ++j) {
            yoko[i][j] = lower_bound(u.begin(), u.end(), v[i][j]) - u.begin();
        }
    }
    for (int i = 0; i < w; ++i) {
        vector<int> u(h);
        for (int j = 0; j < h; ++j) {
            u[j] = v[j][i];
        }
        sort(u.begin(), u.end());
        u.erase(unique(u.begin(), u.end()), u.end());
        tatesize[i] = u.size();
        for (int j = 0; j < h; ++j) {
            tate[j][i] = lower_bound(u.begin(), u.end(), v[j][i]) - u.begin();
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(j) printf(" ");
            if(tate[i][j] == yoko[i][j]){
                printf("%d", max(yokosize[i], tatesize[j]));
            }else if(tate[i][j] < yoko[i][j]){
                printf("%d", max(yokosize[i], tatesize[j]-tate[i][j]+yoko[i][j]));
            }else {
                printf("%d", max(yokosize[i]+tate[i][j]-yoko[i][j], tatesize[j]));
            }
        }
        puts("");
    }
    return 0;
}
