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

string bigger(string &s, string &t){
    if(s.size() > t.size()) return s;
    if(s.size() < t.size()) return t;
    return max(s, t);
}


int main() {
    int w, h;
    while(cin >> w >> h, w){
        vector<string> v(h);
        for (int i = 0; i < h; ++i) {
            cin >> v[i];
        }
        vector<vector<string>> dp(h+1, vector<string>(w+1, "0"));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if(!isdigit(v[i][j])) continue;
                string s = bigger(dp[i+1][j], dp[i][j+1]);
                if(s != "0") dp[i+1][j+1] = s + v[i][j];
                else dp[i+1][j+1] = v[i][j];
            }
        }
        string ans = "0";
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                ans = bigger(ans, dp[i+1][j+1]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}