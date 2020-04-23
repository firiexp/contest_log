#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s, t = "^^*-", u = "*^^-";
    cin >> s;
    int n = s.size();
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] != '(') continue;
        int cnt1 = 0, cnt2 = 0;
        for (int j = i+1; j < n; ++j) {
            if(t[cnt1] == s[j]) cnt1++;
            if(u[cnt2] == s[j]) cnt2++;
            if(s[j] == ')') ans1 += (cnt1 == 3), ans2 += (cnt2 == 3);
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}
