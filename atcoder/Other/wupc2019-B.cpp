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


class UnionFind {
    vector<int> uni;
    int n;
public:
    explicit UnionFind(int n) : uni(static_cast<u32>(n), -1) , n(n){};

    int root(int a){
        if (uni[a] < 0) return a;
        else return (uni[a] = root(uni[a]));
    }

    bool unite(int a, int b) {
        a = root(a);
        b = root(b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a, b);
        uni[a] += uni[b];
        uni[b] = a;
        return true;
    }
};

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int h, w;
    cin >> h >> w;
    int is5 = false;
    auto v = make_v(h+2, w+2, -1);
    int cnt0 = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &v[i+1][j+1]);
            if(v[i+1][j+1] == 5) is5 = true;
            if(v[i+1][j+1] == 0) cnt0++;
        }
    }
    if(!is5 && cnt0 != h*w){
        puts("No");
        return 0;
    }else if(cnt0 == h*w){
        puts("Yes 0");
        return 0;
    }
    UnionFind uf(h*w);
    auto f = [&](int x, int y){ return w*(x-1)+(y-1); };
    int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            for (int k = 0; k < 4; ++k) {
                if(v[i+dy[k]][j+dx[k]] == -1) continue;
                if(v[i][j] <= 5 && v[i+dy[k]][j+dx[k]] <= 5) {
                    uf.unite(f(i, j), f(i+dy[k], j+dx[k]));
                }else if(v[i][j] > 5 && v[i+dy[k]][j+dx[k]] > 5){
                    uf.unite(f(i, j), f(i+dy[k], j+dx[k]));
                }
            }
        }
    }
    vector<int> u(h*w,-1);
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            chmax(u[uf.root(f(i, j))], v[i][j]);
        }
    }

    int ans = 1;
    for (int i = 0; i < h*w; ++i) {
        if(u[i] <= 5) continue;
        if(u[i] == 6) ans += 1;
        if(u[i] == 7) ans += 1;
        if(u[i] == 8) ans += 2;
        if(u[i] == 9) ans += 3;
    }
    cout << "Yes " << ans << "\n";
    return 0;
}
