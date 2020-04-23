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


int p(int a){
    return a & 1 ? a : INF<int> - a;
}
int main() {
    int n;
    cin >> n;
    vector<int> val(n+1, INF<int>), dp1(n+1, INF<int>), dp2(n+1, -INF<int>);
    val[0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; i+j*j <= n; ++j) {
            int to = i+j*j;
            if(val[to] > val[i]+j){
                val[to] = val[i] + j;
                dp1[to] = j;
                dp2[to] = j;
            }else if(val[to] == val[i]+j){
                if(p(dp1[to]) > p(j)) dp1[to] = j;
                if(p(dp1[to]) < p(j)) dp2[to] = j;
            }
        }
    }
    string ans;
    int cur = n; char c = '0';
    while(cur){
        int nxt = (c == '0' ? dp1[cur] : dp2[cur]);
        cur -= nxt*nxt;
        for (int i = 0; i < nxt; ++i) {
            ans += c;
            c = (c == '0' ? '1' : '0');
        }
        c = (c == '0' ? '1' : '0');
    }
    cout << ans << "\n";
    return 0;
}