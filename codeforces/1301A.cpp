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

int solve(){
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if(a[i] == b[i] && b[i] == c[i]) continue;
        else if(a[i] == c[i] || b[i] == c[i]) continue;
        else return 0;
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        puts(solve() ? "YES" : "NO");
    }
    return 0;
}