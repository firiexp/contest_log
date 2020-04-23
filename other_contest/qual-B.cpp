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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

void solve(int n, string &s){
    string ans, t = "ES", u = "SE";
    for (int i = 0; i < 2*n-2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if(s[i] == t[j]){
                ans += u[j];
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n;
        string s;
        cin >> n >> s;
        cout << "Case #" << i << ": ";
        solve(n, s);
    }
    return 0;
}
