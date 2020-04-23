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
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(),s.end());
    s += '0';
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '2'){
            s[i+1]++;
            s[i] = '0';
        }else if(s[i] == '1' && s[i+1] == '1'){
            s[i+1]++;
            s[i] = '0';
            ans++;
        }
    }
    for (int i = 0; i <= n; ++i) {
        ans += s[i] == '1';
    }
    cout << ans << "\n";
    return 0;
}