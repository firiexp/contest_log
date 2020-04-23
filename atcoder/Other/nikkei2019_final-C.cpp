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
    int h, w, k;
    cin >> h >> w >> k;
    vector<ll> a(h+1), b(w+1), A(h+1), B(w+1);
    for (int i = 0; i < h; ++i) a[i+1] = w;
    for (int j = 0; j < w; ++j) b[j+1] = h;
    for (int i = 0; i < k; ++i) {
        int p, q;
        scanf("%d %d", &p, &q);
        a[p]--; b[q]--;
    }
    for (int i = 0; i < h; ++i) A[i+1] = A[i] + a[i+1];
    for (int j = 0; j < w; ++j) B[j+1] = B[j] + b[j+1];
    int cur1 = 0, cur2 = 0;
    while(A[cur1]*2 < A[h]) cur1++;
    while(B[cur2]*2 < B[w]) cur2++;
    ll ans = 0;
    for (int i = 0; i <= h; ++i) ans += llabs(i-cur1)*a[i];
    for (int i = 0; i <= w; ++i) ans += llabs(i-cur2)*b[i];
    cout << ans << "\n";
    return 0;
}
