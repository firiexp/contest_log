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

void solve(){
    long long p1;
    cout << 227 << endl;
    cin >> p1;
    vector<long long> ans(6);
    ans[3] = p1/72057594037927936;
    p1 %= 72057594037927936;
    ans[4] = p1/35184372088832;
    p1 %= 35184372088832;
    ans[5] = p1/137438953472;
    cout << 56 << endl;
    cin >> p1;
    p1 -= ans[3]*16384+ans[4]*2048+ans[5]*512;
    ans[0] = p1/72057594037927936;
    p1 %= 72057594037927936;
    ans[1] = p1/268435456;
    p1 %= 268435456;
    ans[2] = p1/262144;
    for (int i = 0; i < 6; ++i) {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    int ret;
    cin >> ret;
    if(ret == -1) exit(0);
    else return;
}


int main() {
    int t, w;
    cin >> t >> w;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
