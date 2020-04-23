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
int n;


int solve(vector<int> &v, int cur){
    if(cur >= n) return 0;
    if(v[cur] == 0) return solve(v, cur+1);
    int ans = n;
    int w = v[cur];
    for (int i = cur; i < n; ++i) {
        v[i] = (v[i]+10-w)%10;
        ans = min(ans, solve(v, cur+1)+1);
    }
    for (int i = cur; i < n; ++i) {
        v[i] = (v[i]+w)%10;
    }
    return ans;
}

int main() {
    while(cin >> n, n){
        string s, t;
        cin >> s >> t;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = (s[i]-t[i]+10)%10;
        }
        cout << solve(v, 0) << "\n";
    }
    return 0;
}