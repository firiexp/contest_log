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

bool solve(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 0; i < n-1; ++i) {
        int x = max(0, v[i+1]-k);
        m += v[i]-x;
        if(m < 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        puts(solve() ? "YES" : "NO");
    }
    return 0;
}