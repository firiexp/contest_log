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
    vector<int> m;
    int n, a, p = 0, q = 0;
    cin >> n >> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        m.emplace_back(x-a);
    }
    vector<vector<ll>> v(2, vector<ll>(10001, 0));
    v[0][5000] = 1;
    for (int i = 0; i < n; ++i) {
        int prv = i % 2, now = prv^1;
        int b = m[i];
        v[now].assign(10001, 0);
        for (int j = p; j <= q; ++j) {
            v[now][5000+j+b] += v[prv][5000+j];
            v[now][5000+j] += v[prv][5000+j];
        }
        p = min(p, p+b); q = max(q, q+b);
    }
    cout << v[n%2][5000]-1 << "\n";
    return 0;
}
