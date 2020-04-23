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
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> v(k);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> u = v;
    sort(u.begin(), u.end());
    vector<int> u2(k);
    for (int i = 0; i < k; ++i) {
        u2[i] = u[i] + 100*(n-m);
    }
    for (int i = 0; i < k; ++i) {
        int x = u2.end() - upper_bound(u2.begin(), u2.end(), v[i]);
        if(m < n) x--;
        if(x*12 < k) printf("%d\n", i+1);
    }
    puts("--------");
    for (int i = 0; i < k; ++i) {
        int x = u.end() - upper_bound(u.begin(), u.end(), v[i]+(n-m)*100);
        if(x*12 < k) printf("%d\n", i+1);
    }
    return 0;
}
