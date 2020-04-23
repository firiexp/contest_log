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

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll ans = 0;
        vector<vector<int>> v(n);
        for (int i = 0; i < n; ++i) {
            int m, p;
            scanf("%d %d", &m, &p);
            v[m].emplace_back(p);
            ans += p;
        }
        priority_queue<int> Q;
        for (int i = 0; i < n; ++i) {
            for(auto &&j : v[i]) Q.push(j);
            if(!Q.empty()) ans -= Q.top(), Q.pop();
        }
        printf("%lld\n", ans);
    }
    return 0;
}