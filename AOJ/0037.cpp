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



int main() {
    int dp[5][5][4] = {};
    string d = "RDLU";
    cout << "R";
    array<int, 4> dy{0, 1, 0, -1}, dx{1, 0, -1, 0};
    for (int i = 0; i < 9; ++i) {
        string s;
        cin >> s;
        if(i&1){
            for (int j = 0; j < 5; ++j) {
                if(s[j] == '1'){
                    dp[i/2][j][1] = dp[i/2+1][j][3] = 1;
                }
            }
        }else {
            for (int j = 0; j < 4; ++j) {
                if(s[j] == '1'){
                    dp[i/2][j][0] = dp[i/2][j+1][2] = 1;
                }
            }
        }
    }
    int y = 0, x = 0, cur = 0, started = 0;
    for (int i = 0; !started || y || x; ++i) {
        if(dp[y][x][(cur+3)&3]){
            cur = (cur+3)&3;
            cout << d[cur];
            y += dy[cur], x += dx[cur];
        } else if(dp[y][x][cur]){
            started = 1;
            cout << d[cur];
            y += dy[cur]; x += dx[cur];
        }else cur = (cur+1)&3;
    }
    puts("");
    return 0;
}