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
    auto v = make_v(h, w, false);
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) v[i][j] = s[j] == '#';
    }
    auto v2 = make_v(h-1, w-1, 0);
    h--; w--;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            v2[i][j] = 1-(v[i][j] ^ v[i][j+1] ^ v[i+1][j] ^ v[i+1][j+1]);
        }
    }
    for (int i = 1; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(v2[i][j]) v2[i][j] += v2[i-1][j];
        }
    }

    int ans = max(h+1, w+1);
    for (int i = 0; i < h; ++i) {
        stack<int> S;
        vector<int> l(w), r(w);
        for (int j = 0; j < w; ++j) {
            while(!S.empty() && v2[i][S.top()] >= v2[i][j]) S.pop();
            l[j] = (S.empty() ? 0 : S.top() + 1);
            S.emplace(j);
        }
        while(!S.empty()) S.pop();
        for (int j = w-1; j >= 0; --j) {
            while(!S.empty() && v2[i][S.top()] >= v2[i][j]) S.pop();
            r[j] = (S.empty() ? w : S.top());
            S.emplace(j);
        }
        for (int j = 0; j < w; ++j) {
            chmax(ans, (v2[i][j]+1)*(r[j]-l[j]+1));
        }
    }
    cout << ans << "\n";
    return 0;
}
