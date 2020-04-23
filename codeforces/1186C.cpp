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
    string s, t;
    cin >> s >> t;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < t.size(); ++i) {
        cnt1 += (s[i]-'0');
        cnt2 += (t[i]-'0');
    }
    int ans = 0;
    if(cnt1%2 == cnt2%2) ans++;
    int cur = t.size();
    while(cur < s.size()){
        cnt1 -= s[cur-(int)t.size()]-'0';
        cnt1 += s[cur]-'0';
        if(cnt1%2 == cnt2%2) ans++;
        cur++;
    }
    cout << ans << "\n";
    return 0;
}