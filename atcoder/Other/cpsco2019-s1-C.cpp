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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> u(n);
    for (int i = 0; i < k; ++i) {
        u[n-i-1]++;
    }
    vector<int> li = {
            1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000,
            5, 50, 500, 5000, 50000, 500000, 5000000, 50000000, 500000000
    };
    sort(li.begin(),li.end(), greater<>());
    int ans = INF<int>;
    int cnt = 0;
    do {
        int s = 0;
        for (int i = 0; i < n; ++i) {
            if(u[i]) s += v[i];
        }
        int p = 0;
        for (int i : li) {
            p += s/i;
            s %= i;
        }
        ans = min(ans, p);
    }while(next_permutation(u.begin(),u.end()));
    cout << ans << "\n";
    return 0;
}