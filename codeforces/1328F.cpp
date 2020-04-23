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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    vector<pair<int, int>> rle;
    rle.emplace_back(v[0], 1);
    for (int i = 1; i < n; ++i) {
        if(v[i] == rle.back().first){
            rle.back().second++;
        }else {
            rle.emplace_back(v[i], 1);
        }
    }
    for (auto &&j : rle) {
        if(j.second >= k){
            puts("0");
            return 0;
        }
    }
    ll s = 0, cnt = 0, ans = INF<ll>;
    vector<ll> dp1(rle.size()), dp2(rle.size());
    for (int i = 0; i < rle.size(); ++i) {
        dp1[i] = (rle[i].first-1)*cnt - s;
        s += (ll)rle[i].first*rle[i].second;
        cnt += rle[i].second;
        if(cnt >= k) {
            ans = min(ans, dp1[i]+k-rle[i].second);
        }
    }
    s = 0, cnt = 0;
    for (int i = rle.size()-1; i >= 0; --i) {
        dp2[i]= s-(rle[i].first+1)*cnt;
        s += (ll)rle[i].first*rle[i].second;
        cnt += rle[i].second;
        if(cnt >= k) ans = min(ans, dp2[i]+k-rle[i].second);
    }
    for (int i = 1; i+1 < rle.size(); ++i) {
        ans = min(ans, dp1[i]+dp2[i]+k-rle[i].second);
    }
    cout << ans << "\n";
    return 0;
}