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

void solve(){
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto &&i : s) {
        if(i == 'B') a++;
        if(i == '.') b++;
    }
    if(a && b && a >= b) {
        puts("Y");
        return;
    }
    if(b && a >= 2){
        puts("Y");
        return;
    }
    puts("N");
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}