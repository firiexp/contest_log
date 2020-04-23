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

int main() {
    int q;
    cin >> q;
    while(q--){
        int n, r;
        scanf("%d %d", &n, &r);
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        sort(v.begin(),v.end(), greater<>());
        v.erase(unique(v.begin(), v.end()), v.end());
        ll val = 0, ans = 0, cur = 0;
        while(cur < v.size()) {
            if(v[cur]+val > 0){
                val -= r;
                cur++; ans++;
            }else break;
        }
        printf("%lld\n", ans);
    }
    return 0;
}