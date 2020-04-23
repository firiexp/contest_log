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


int main() {
    ll h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<ll> hs, ws;
    for (int i = 0; i < n; ++i) {
        hs.emplace_back(i);
        hs.emplace_back(i+h-n+1);
        for (int j = 0; j < m; ++j) {
            ws.emplace_back(j);
            ws.emplace_back(j+w-m+1);
        }
    }
    sort(hs.begin(), hs.end());
    hs.erase(unique(hs.begin(), hs.end()), hs.end());
    sort(ws.begin(), ws.end());
    ws.erase(unique(ws.begin(), ws.end()), ws.end());
    auto grid = make_v(hs.size()+1, ws.size()+1, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if(s[j] == '#'){
                ll a = i+h-n+1, b = j+w-m+1;
                auto y1 = lower_bound(hs.begin(), hs.end(), i) - hs.begin();
                auto y2 = lower_bound(hs.begin(), hs.end(), a) - hs.begin();
                auto x1 = lower_bound(ws.begin(), ws.end(), j) - ws.begin();
                auto x2 = lower_bound(ws.begin(), ws.end(), b) - ws.begin();
                grid[y2][x2]++; grid[y2][x1]--; grid[y1][x2]--; grid[y1][x1]++;
            }
        }
    }
    for (int i = 0; i <= hs.size(); ++i) {
        for (int j = 1; j <= ws.size(); ++j) {
            grid[i][j] += grid[i][j-1];
        }
    }
    for (int i = 1; i <= hs.size(); ++i) {
        for (int j = 0; j <= ws.size(); ++j) {
            grid[i][j] += grid[i-1][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < hs.size()-1; ++i) {
        for (int j = 0; j < ws.size()-1; ++j) {
            if(grid[i][j] > 0) {
                ans += (hs[i+1]-hs[i])*(ws[j+1]-ws[j]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
