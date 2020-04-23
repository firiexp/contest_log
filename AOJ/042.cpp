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
    int w, cut = 1;
    while(cin >> w, w){
        int n;
        cin >> n;
        vector<int> dp(w+1, -INF<int>);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int a, b;
            scanf("%d,%d", &a, &b);
            for (int j = w-b; j >= 0; --j) {
                dp[j+b] = max(dp[j+b], dp[j]+a);
            }
        }
        auto ans = max_element(dp.begin(),dp.end());
        printf("Case %d:\n%d\n%ld\n", cut++, *ans, ans-dp.begin());
    }
    return 0;
}