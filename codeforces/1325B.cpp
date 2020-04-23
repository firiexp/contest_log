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

void solve(){
    int n; scanf("%d", &n);
    vector<int> v(n); for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    printf("%zu\n", v.size());
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}