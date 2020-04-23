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

static const int MOD = 998244353;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int gauss_jordan(vector<bitset<300>> &a){
    int n = a.size(), m = 300;
    int cnt = 0;
    for (int i = 0; i < m && cnt != n; ++i) {
        int p = cnt;
        for (int j = cnt; j < n; ++j) {
            if(a[j][i]){
                p = j;
                break;
            }
        }
        if((a[p][i]) == 0) continue;
        swap(a[cnt], a[p]);
        for (int j = 0; j < n; ++j) {
            if(cnt == j) continue;
            if(a[j][i]) a[j] ^= a[cnt];
        }
        cnt++;
    }
    a.erase(a.begin()+cnt, a.begin()+n);
    return cnt;
}

template <class T>
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<bitset<300>> v(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            scanf("%d" ,&x);
            if(x) v[i].set(j);
        }
    }
    int rank = gauss_jordan(v);
    ll ans1 = pow_(2, m-1, MOD), ans2 = MOD+pow_(2, n, MOD)-pow_(2, n-rank, MOD);
    cout << (ans1*ans2)%MOD << "\n";
    return 0;
}