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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> v(n), u(n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        v[i] = x-1;
        u[x-1] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] != i){
            int j = u[i];
            swap(v[i], v[j]);
            u[v[i]] = i;
            u[v[j]] = j;
            ans++;
        }
    }
    puts((ans&1) == (k&1) && ans <= k ? "YES" : "NO");
    return 0;
}
