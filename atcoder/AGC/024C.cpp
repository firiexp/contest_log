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

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    if(v.front() != 0){
        puts("-1");
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i < n-1; ++i) {
        if(v[i+1] > v[i]+1){
            puts("-1");
            return 0;
        }
        if(v[i+1] == v[i]+1) ans++;
        else ans += v[i+1];
    }
    cout << ans << "\n";
    return 0;
}
