#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(m+1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    a[n] = -1, b[m] = -1;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    if(a.size() != n+1 || b.size() != m+1 || a[n] != n*m || b[m] != n*m){
        puts("0");
        return 0;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    ll ans = 1, p = 0, q = 0, c = 0;
    for (int j = n*m; j >= 1; --j) {
        while(a[p+1] >= j) p++;
        while(b[q+1] >= j) q++;
        if(a[p] == j && b[q] == j) {}
        else if(a[p] == j){
            (ans *= q+1) %= MOD;
        }else if(b[q] == j){
            (ans *= p+1) %= MOD;
        }else {
            (ans *= ((p+1)*(q+1)-c)) %= MOD;
        }
        c++;
    }
    cout << ans << "\n";
    return 0;
}
