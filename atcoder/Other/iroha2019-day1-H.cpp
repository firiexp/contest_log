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
    ll n;
    cin >> n;
    string s = to_string(n);
    int sum = 0;
    for (auto &&i : s) {
        sum += i-'0';
    }
    int ss = sum;
    string ans;
    while(sum >= 9) sum -= 9, ans += '9';
    if(sum) ans += char(sum+'0');
    sort(ans.begin(),ans.end());
    if(s != ans){
        cout << ans << "\n";
    }else {
        if(s.size() == 1){
            cout << 1 << s[0]-'1' << "\n";
        }else {
            if(ans[0] != '9') {
                ans[0]++; ans[1]--;
            } else {
                ans = string(1, '1') + ans;
                ans[1]--;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}