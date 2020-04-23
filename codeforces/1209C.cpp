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

string solve() {
    int n; string s;
    cin >> n >> s;
    for (int i = 0; i <= 9; ++i) {
        vector<int> ans(n);
        int x = 0, y = i;
        int ok = 1;
        for (int j = 0; j < n; ++j) {
            if(s[j]-'0' == i){
                if(y == i) ans[j] = 2;
                else if(x <= i) x = i, ans[j] = 1;
                else {
                    ok = 0;
                    break;
                }
            }else if(s[j] - '0' < i) {
                if(x <= s[j] - '0') x = s[j] - '0', ans[j] = 1;
                else {
                    ok = 0;
                    break;
                }
            }else {
                if(y <= s[j] - '0') y = s[j] - '0', ans[j] = 2;
                else {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok){
            string ret;
            for (int j = 0; j < n; ++j) {
                ret += to_string(ans[j]);
            }
            return ret;
        }
    }
    return "-";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
    return 0;
}