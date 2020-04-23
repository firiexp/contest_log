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

constexpr int M = 1000000;
array<int, M+1> dp{};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        dp[x] = 1;
    }
    for (int i = 1; i <= M; ++i) {
        if(!dp[i]) continue;
        for (int j = i*2; j <= M; j += i) {
            if(!dp[j]) continue;
            dp[j] = max(dp[j], dp[i]+1);
        }
    }
    cout << *max_element(dp.begin(),dp.end()) << "\n";
    return 0;
}