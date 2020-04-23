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
    int n; string s, t;
    cin >> n >> s >> t;
    vector<int> cnt1(10), cnt2(10);
    for (int i = 0; i < n; ++i) {
        cnt1[s[i]-'0']++; cnt2[t[i]-'0']++;
    }
    int ans1 = n;
    for (int j = 9; j >= 0; --j) {
        ans1 -= min(cnt1[j],cnt2[j]);
        if(j) cnt2[j-1] += cnt2[j]-min(cnt1[j],cnt2[j]);
    }
    int ans2 = 0;
    cnt1 = cnt2 = vector<int>(10);
    for (int i = 0; i < n; ++i) {
        cnt1[s[i]-'0']++; cnt2[t[i]-'0']++;
    }
    for (int j = 9; j > 0; --j) {
        ans2 += min(cnt1[j-1],cnt2[j]);
        cnt2[j-1] += cnt2[j]-min(cnt1[j-1],cnt2[j]);
    }
    cout << ans1 << "\n";
    cout << ans2 << "\n";
    return 0;
}