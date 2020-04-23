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
    int n, k;
    cin >> n >> k;
    int m = 1;
    while(n > k*m || n > m*m) m++;
    int cur = 0;
    cout << m << "\n";
    vector<string> ans(m, string(m, '.'));
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < min(k, m); ++j) {
            if(cnt < n){
                ans[i][cur] = '#';
                cur = (cur+1)%m;
                cnt++;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}