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
    int n; string s;
    cin >> n >> s;
    s = "0" + s + "0";
    vector<int> dp(n+2);
    for (int i = 1; i <= n; ++i) {
        dp[i+1] = max(dp[i+1], dp[i]);
        if(s.substr(i-1, 3) == "101"){
            int cur = i-1;
            while(s[cur] != '0'){
                dp[i+1] = max(dp[i+1], dp[cur-1]+ (i-cur));
                cur--;
            }
            cur = i+1;
            while(s[cur] != '0'){
                dp[cur] = max(dp[cur], dp[i-2]+ (cur-i));
                cur++;
            }
        }
    }
    cout << dp.back() << "\n";
    return 0;
}