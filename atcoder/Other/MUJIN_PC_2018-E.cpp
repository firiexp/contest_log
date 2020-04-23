#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s += s;
    auto grid = make_v(n+2, m+2, 0);
    auto ans = make_v(n+2, m+2, INF<ll>);
    auto next = make_v(4, k, INF<int>);
    int sx = 0, sy = 0, gx = 0, gy = 0;
    char li[] = {'U', 'D', 'L', 'R'};
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    for (int i = k-1; i < 2*k; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(s[i] == li[j]) next[j][k-1] = min(next[j][k-1], i-k+2);
        }
    }
    for (int i = k-2; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if(s[i] == li[j]) next[j][i] = 1;
            else next[j][i] = min(next[j][i], next[j][i+1]+1);
        }
    }
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        for (int j = 0; j < m; ++j) {
            if(t[j] != '#') grid[i+1][j+1] = 1;
            if(t[j] == 'S') sx = i+1, sy = j+1;
            if(t[j] == 'G') gx = i+1, gy = j+1;
        }
    }

    GPQ<tuple<ll, int, int>> q;
    q.emplace(0, sx, sy);
    while (!q.empty()){
        int x, y;
        ll time;
        tie(time, x, y) = q.top(); q.pop();
        if(ans[x][y] != INF<ll>) continue;
        ans[x][y] = time;
        for (int i = 0; i < 4; ++i) {
            if(ans[x+dx[i]][y+dy[i]] == INF<ll> && grid[x+dx[i]][y+dy[i]] && next[i][time%k] != INF<int>){
                q.emplace(time + next[i][time%k],x+dx[i], y+dy[i]);
            }
        }
    }
    cout << (ans[gx][gy] == INF<ll> ? -1 : ans[gx][gy]) << "\n";
    return 0;
}
