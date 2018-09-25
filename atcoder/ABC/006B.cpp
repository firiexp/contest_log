#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 10007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp = {0, 0, 1};
    for (int i = 2; i < n; ++i) {
        dp.emplace_back((dp[i-2]+dp[i-1]+dp[i])%INF);
    }
    cout << dp[n-1] << "\n";
    return 0;
}
