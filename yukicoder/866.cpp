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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int dp[2001][2001][26];
int main() {
    int h, w, k;
    cin >> h >> w >> k;
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j <= w; ++j) {
            for (int l = 0; l < 26; ++l) {
                dp[i][j][l] = 0;
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            dp[i+1][j+1][s[j]-'a'] = 1;
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 0; j <= w; ++j) {
            for (int l = 0; l < 26; ++l) {
                dp[i][j][l] += dp[i-1][j][l];
            }
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 0; j <= w; ++j) {
            for (int l = 0; l < 26; ++l) {
                dp[i][j][l] += dp[i][j-1][l];
            }
        }
    }
    
    return 0;
}