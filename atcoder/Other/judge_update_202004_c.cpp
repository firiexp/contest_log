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
    int a, b, c;
    cin >> a >> b >> c;
    int n = a+b+c;
    int ans = 0;
    auto dfs = [&](int aa, int bb, int cc, auto &&f){
        if(aa < bb || bb < cc) return;
        if(!n) {
            ans++;
            return;
        }
        n--;
        if(a != aa) f(aa+1, bb, cc, f);
        if(b != bb) f(aa, bb+1, cc, f);
        if(c != cc) f(aa, bb, cc+1, f);
        n++;
    };
    dfs(0, 0, 0, dfs);
    cout << ans << "\n";
    return 0;
}