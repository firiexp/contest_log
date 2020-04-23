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
    int t;
    cin >> t;
    while(t--){
        int n; string s;
        cin >> n >> s;
        int cnt = 0, l = n, r = -1;
        for (int i = 0; i < n; ++i) {
            if(s[i] == '1'){
                cnt++;
                l = min(l, i);
                r = max(r, i);
            }
        }
        cout << max({n+cnt, 2*(r+1), 2*(n-l)}) << "\n";
    }
    return 0;
}