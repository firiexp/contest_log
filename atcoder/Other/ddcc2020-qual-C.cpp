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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> v(h);
    vector<int> a;
    auto ans = make_v(h, w, 0);
    a.emplace_back(-1);
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == '#') v[i].emplace_back(j);
        }
        if(!v[i].empty()) {
            v[i].emplace_back(w);
            a.emplace_back(i);
        }
    }
    int cnt = 1;
    for (int i = 1; i < a.size(); ++i) { // i番目の列
        int l = -1;
        for (int j = 0; j+1 < v[a[i]].size(); ++j) {
            for (int y = a[i-1]+1; y <= a[i]; ++y) {
                for (int x = l+1; x <= v[a[i]][j]; ++x) {
                    ans[y][x] = cnt;
                }
            }
            cnt++;
            l = v[a[i]][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 1; j < w; ++j) {
            if(!ans[i][j] && ans[i][j-1]){
                ans[i][j] = ans[i][j-1];
            }
        }
    }
    for (int i = 1; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(!ans[i][j] && ans[i-1][j]){
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(j) printf(" ");
            printf("%d", ans[i][j]);
        }
        puts("");
    }
    return 0;
}