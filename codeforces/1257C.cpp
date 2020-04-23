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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        map<int, int> m;
        int ans = INF<int>;
        for (int i = 0; i < n; ++i) {
            if(m.count(v[i])) ans = min(ans, i-m[v[i]]+1);
            m[v[i]] = i;
        }
        cout << (ans == INF<int> ? -1 : ans) << "\n";
    }
    return 0;
}