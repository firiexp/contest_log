#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;
using namespace std;
static const ll INF = 20000000000000LL;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> v(2, vector<ll>(2001, INF));
    v[0][0] = 0;
    ll bats[2001] {}, a[2001];
    fill_n(&bats[0], 2000, 0);
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        bats[i] = sum;
    }
    bats[0] = 1;
    a[0] = 0;
    if(bats[n] == k){
        cout << 1 << "\n";
        return 0;
    }
    v[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int now = i % 2, nex = (i+1)%2;
        fill(v[nex].begin(), v[nex].end(), INF);
        for (int j = 0; j <= i; j++) {
            if(v[now][j] == INF) continue;
            v[nex][j] = min(v[nex][j], v[now][j]);
            ll e = min(v[now][j] * a[i+1] /bats[i] + 1, INF);
            v[nex][j+1] = min(v[nex][j+1], v[now][j]+e);
        }
    }
    for (int i = n; i >= 0; --i) {
        if(v[n%2][i] <= k){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
