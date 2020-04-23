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
    int n; ll x;
    cin >> n >> x;
    const ll bound = 22300, sz = 2230000;
    vector<pair<ll, int>> a1, a2;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if(a <= bound) a1.emplace_back(a, i);
        else a2.emplace_back(a, i);
    }
    vector<bitset<sz+1>> dp1(a1.size()+1);
    dp1[0].set(0);
    for (int i = 0; i < a1.size(); ++i) {
        dp1[i+1] = dp1[i] | (dp1[i] << a1[i].first);
    }
    vector<ll> dp2(1 << a2.size());
    for (int i = 0; i < 1 << a2.size(); ++i) {
        if(i) dp2[i] = dp2[i ^ (i & -i)] + a2[__builtin_ctz(i)].first;
        if(dp2[i] <= x && x-dp2[i] <= sz && dp1.back()[x-dp2[i]]){
            ll A = x-dp2[i];
            string ans(n, 'x');
            for (int j = (int)a1.size()-1; j >= 0; --j) {
                if(A >= a1[j].first && dp1[j][A-a1[j].first]) {
                    ans[a1[j].second] = 'o';
                    A -= a1[j].first;
                }
            }
            for (int j = 0; j < a2.size(); ++j) {
                if(i & (1 << j)){
                    ans[a2[j].second] = 'o';
                }
            }
            cout << ans << "\n";
            return 0;
        }
    }
    puts("No");
    return 0;
}