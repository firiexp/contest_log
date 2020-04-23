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
    int a, b;
    cin >> a >> b;
    if(__gcd(a, b) != 1){
        puts("-1");
    }else {
        int M = 1000000;
        vector<int> dp(M+1);
        int cnt = 0;
        dp[0] = 1;
        for (int i = 0; i <= M; ++i) {
            if(!dp[i]) {
                cnt++;
                continue;
            }
            if(i+a <= M){
                dp[i+a] = 1;
            }
            if(i+b <= M){
                dp[i+b] = 1;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}