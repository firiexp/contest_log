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
    int n;
    cin >> n;
    vector<ll> a(n), x(n), y(n);
    for (auto &&i : a) scanf("%lld", &i);
    for (auto &&j : x) scanf("%lld", &j);
    for (auto &&k : y) scanf("%lld", &k);
    vector<ll> dp(n+1);
    auto cost = [&](int i, int j){
        if(i > j || n < j) return INF<ll>;
        return dp[i]+abs(x[i]-a[j-1])+y[i];
    };
    deque<pair<int, int>> Q;
    Q.emplace_back(0, 1);
    for (int j = 1; j <= n; ++j) {
        int l = Q.front().first;
        if(cost(j-1, j) <= cost(l, j)){
            dp[j] = cost(j-1, j);
            Q.clear();
            Q.emplace_back(j-1, j+1);
        }else {
            dp[j] = cost(l, j);
            while(cost(j-1, Q.back().second) <= cost(Q.back().first, Q.back().second)) Q.pop_back();
            int ng = j-1, ok = n+1;
            while(ok-ng > 1){
                int mid = (ok+ng)/2;
                if(cost(j-1, mid) <= cost(Q.back().first, mid)) ok = mid;
                else ng = mid;
            }
            Q.emplace_back(j-1, ok);
            if(Q.size() >= 2 && j+1 == Q[1].second) Q.pop_front();
            else Q.front().second++;
        }
    }
    cout << dp.back() << "\n";
    return 0;
}