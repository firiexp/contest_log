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
        if(i >= j || n < j) return INF<ll>;
        return dp[i]+abs(x[i]-a[j-1])*abs(x[i]-a[j-1])*abs(x[i]-a[j-1])+y[i]*y[i]*y[i];
    };
    vector<int> N(n, INF<int>), F(n, 0);
    int c = 1, r = 0;
    while(c <= n){
        int p = min(2*c-r, n);
        vector<int> row(p-c+1), col(c-r+1);
        iota(row.begin(),row.end(), c);
        iota(col.begin(),col.end(), r);
        auto smawk = [&](vector<int> &row, vector<int> &col, auto &&f) -> vector<int> {
            if(row.empty()) return {};
            vector<int> c2, r2;
            for (auto &&i : col) {
                while(!c2.empty() && cost(row[c2.size()-1], i) <= cost(c2.back(), i)) c2.pop_back();
                if(c2.size() < row.size()) c2.emplace_back(i);
            }
            for (int i = 1; i < n; i += 2) r2.emplace_back(row[i]);
            auto a2 = f(r2, c2, f);
            vector<int> ans(row.size());
            for (int i = 0; i < a2.size(); ++i) ans[i*2+1] = a2[i];
            int j = 0;
            for (int i = 0; i < row.size(); i += 2) {
                ans[i] = c2[j];
                int end = i+1 == row.size() ? c2.back() : ans[i+1];
                while(c2[j] != end){
                    j++;
                    if(cost(row[i], c2[j]) <= cost(ans[i], c2[j])){
                        ans[i] = c2[j];
                    }
                }
            }
            return ans;
        };
        auto vv = smawk(row, col, smawk);

    }
    return 0;
}