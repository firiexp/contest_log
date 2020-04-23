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
    int n, k; string s;
    cin >> n >> k >> s;
    int ans = 0, cur = 0, a = 0, prva = 0, prvans = 0;
    for (int i = 0; i < k; ++i) {
        if(a == 0) ans++;
        else a--;
        a += s[cur]-'0';
        cur++;
        if(cur == n) {
            cur = 0;
            if(a >= n){
                cout << ans << "\n";
                return 0;
            }else if(a == prva){
                ans += (ans-prvans)*(k/n-i/n-1);
                i = k/n*n-1;
            }
            prva = a;
            prvans = ans;
        }
    }
    cout << ans << "\n";
    return 0;
}