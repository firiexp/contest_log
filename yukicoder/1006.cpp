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
    int n;
    cin >> n;
    vector<int> v(n+1);
    iota(v.begin(),v.end(), 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            v[j]--;
        }
    }
    int ans = INF<int>;
    for (int i = 1; i < n; ++i) {
        ans = min(ans, abs(v[i]-v[n-i]));
    }
    for (int i = 1; i < n; ++i) {
        if(abs(v[i]-v[n-i]) == ans) {
            printf("%d %d\n", i, n-i) ;
        }
    }
    return 0;
}