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

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> g(h + 2, vector<int>(w + 2, 0));
    auto x = g;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            g[i + 1][j + 1] = (s[j] == '.');
        }
    }
    for (int i = 0; i < h; ++i) {
        int c = 0;
        for (int j = 0; j < w; ++j) {
            x[i + 1][j + 1] += c;
            if (g[i + 1][j + 1]) c++;
            else c = 0;
        }
    }
    for (int i = 0; i < h; ++i) {
        int c = 0;
        for (int j = w-1; j >= 0; --j) {
            x[i + 1][j + 1] += c;
            if (g[i + 1][j + 1]) c++;
            else c = 0;
        }
    }
    for (int j = 0; j < w; ++j) {
        int c = 0;
        for (int i = 0; i < h; ++i) {
            x[i + 1][j + 1] += c;
            if (g[i + 1][j + 1]) c++;
            else c = 0;
        }
    }
    for (int j = 0; j < w; ++j) {
        int c = 0;
        for (int i = h-1; i >= 0; --i) {
            x[i + 1][j + 1] += c;
            if (g[i + 1][j + 1]) c++;
            else c = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (g[i+1][j + 1]) {
                ans = max(ans, x[i+1][j + 1] + 1);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}