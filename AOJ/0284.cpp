#include <iostream>
#include <algorithm>
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

using real = int;
struct Point {
    real x, y;
    Point& operator+=(const Point a) { x += a.x; y += a.y;  return *this; }
    Point& operator-=(const Point a) { x -= a.x; y -= a.y;  return *this; }
    Point& operator*=(const real k) { x *= k; y *= k;  return *this; }
    Point& operator/=(const real k) { x /= k; y /= k;  return *this; }
    Point operator+(const Point a) const {return Point(*this) += a; }
    Point operator-(const Point a) const {return Point(*this) -= a; }
    Point operator*(const real k) const {return Point(*this) *= k; }
    Point operator/(const real k) const {return Point(*this) /= k; }
    bool operator<(const Point &a) const { return (x != a.x ? x < a.x : y < a.y); }
    explicit Point(real a = 0, real b = 0) : x(a), y(b) {};
};

istream& operator>> (istream& s, Point& P){
    s >> P.x >> P.y;
    return s;
}




template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }




int dp[41][40][40][40], prv[41][40][40][40];

int main() {
    int n;
    cin >> n;
    vector<Point> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    auto area = [](Point a, Point b, Point c){ return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x); };
    auto to = make_v(n, n, vector<int>());
    fill_n((int*)dp, 41*40*40*40, INF<int>);
    fill_n((int*)prv, 41*40*40*40, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            if(v[i].y <= v[j].y) dp[2][i][i][j] = 0;
            for (int k = 0; k < n; ++k) {
                if(i == k || j == k) continue;
                if(area(v[i], v[j], v[k]) > 0 && (v[i].y <= v[j].y || v[j].y >= v[k].y)){
                    to[i][j].emplace_back(k);
                }
            }
        }
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < n; ++l) {
                    if(dp[i][j][k][l] == INF<int>) continue;
                    for (auto &&m : to[k][l]) {
                        if(v[j].y > v[m].y || j == m) continue;
                        int a = area(v[j], v[l], v[m]);

                        if(a > 0 && dp[i+1][j][l][m] > dp[i][j][k][l]+a){
                            dp[i+1][j][l][m] = dp[i][j][k][l]+a;
                            prv[i+1][j][l][m] = k;
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> anss(n+1);
    for (int i = 3; i <= n; ++i) {
        int val = INF<int>, a = 0, b = 0, c = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < n; ++l) {
                    if(dp[i][j][k][l] < val){
                        val = dp[i][j][k][l];
                        a = j; b = k; c = l;
                    }
                }
            }
        }
        if(val == INF<int>) {
            continue;
        }
        vector<int> ans{c, b};
        for (int j = i; j >= 3; --j) {
            int x = prv[j][a][b][c];
            ans.emplace_back(x);
            c = b; b = x;
        }
        reverse(ans.begin(),ans.end());
        if(v[ans.front()].y == v[ans.back()].y){
            rotate(ans.begin(), ans.end()-1, ans.end());
        }
        anss[i] = ans;
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        if(anss[x].empty()) puts("NA");
        else{
            for (int i = 0; i < anss[x].size(); ++i) {
                printf(i ? " %d" : "%d", anss[x][i]+1);
            }
            puts("");
        }
    }
    return 0;
}