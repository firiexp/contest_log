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
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) scanf("%d", &i);
    int m;
    cin >> m;
    vector<int> B(m);
    for (auto &&j : B) scanf("%d", &j);
    sort(B.begin(),B.end(), greater<>());
    vector<pair<int, int>> dp(1<<n, {m, 0});
    dp[0] = {0, 0};
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                if(dp[i ^ (1 << j)].second + A[j] <= B[dp[i ^ (1 << j)].first]){
                    dp[i] = min(dp[i], {dp[i ^ (1 << j)].first, dp[i ^ (1 << j)].second+A[j]});
                }else if(dp[i ^ (1 << j)].first != m-1 && A[j] <= B[dp[i ^ (1 << j)].first+1]){
                    dp[i] = min(dp[i], {dp[i ^ (1 << j)].first+1, A[j]});
                }
            }
        }
    }
    cout << (dp.back().first == m ? -1 : dp.back().first+1) << '\n';
    return 0;
}