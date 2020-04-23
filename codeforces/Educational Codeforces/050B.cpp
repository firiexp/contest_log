#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll n, m, k;
        cin >> n >> m >> k;
        if(n > m) swap(n, m);
        if(n%2 != m%2) k--, m--;
        else if(m%2 != k%2) n--, m--, k -= 2;
        if(k < m) puts("-1");
        else cout << k << "\n";
    };
    return 0;
}
