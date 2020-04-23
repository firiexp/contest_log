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
#include <unordered_map>
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int dp[50][50][50][50];
int main() {
    int h, w;
    cin >> w >> h;
    int n;
    cin >> n;
    vector<pair<int, int>> P(n);
    vector<int> ys{0, h+1}, xs{0, w+1};
    for (auto &&i : P) {
        cin >> i.second >> i.first;
        ys.emplace_back(i.first); xs.emplace_back(i.second);
    }
    sort(ys.begin(),ys.end());
    sort(xs.begin(),xs.end());
    for (int i = 0; i < n; ++i) {
        P[i].first = lower_bound(ys.begin(),ys.end(), P[i].first) - ys.begin();
        P[i].second = lower_bound(xs.begin(),xs.end(), P[i].second) - xs.begin();
    }
    for(auto &&i : dp) for(auto &&j : i) for(auto &&k : j) fill_n(k, n, 0);
    h = ys.size(), w = xs.size();
    int ans = 0;
    for (int len1 = 1; len1 < h; ++len1) {
        for (int len2 = 1; len2 < w; ++len2) {
            for (int i = 0; i+len1 < h; ++i) {
                for (int j = 0; j+len2 < w; ++j) {
                    for (int k = 0; k < n; ++k) {
                        int y, x; tie(y, x) = P[k];
                        if(i < y && y < i+len1 && j < x && x < j+len2){
                            chmax(dp[i][j][i+len1][j+len2],
                                    dp[i][j][y][x]
                                    +dp[y][j][i+len1][x]
                                    +dp[i][x][y][j+len2]
                                    +dp[y][x][i+len1][j+len2]
                                    +(ys[i+len1]-ys[i])
                                    +(xs[j+len2]-xs[j])
                                    -3);
                        }
                    }
                    chmax(ans, dp[i][j][i+len1][j+len2]);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}