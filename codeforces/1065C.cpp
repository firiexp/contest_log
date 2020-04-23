#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, k, xmax = -1, xmin = INF<int>;
    cin >> n >> k;
    vector<ll> v(200002, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[x]++;
        xmax = max(xmax, x);
        xmin = min(xmin, x);
    }
    ll sum = 0;
    for (int i = xmax; i >= xmin+1; --i) {
        sum += v[i];
        v[i] = sum;
    }
    sum = 0;
    for (int i = xmax; i >= xmin+1; --i) {
        sum += v[i];
        v[i] = sum;
    }
    for (int i = 0; i < xmin+1; ++i) {
        v[i] = sum;
    }
    for (int i = 0; i < (xmax+2)/2; ++i) {
        swap(v[i], v[xmax+1-i]);
    }
    int l = 1, ans = 0;
    for (int i = 0; i <= xmax+1; ++i) {
        if(v[i+1]-v[l-1] > k) {
            ans++;
            l = i+1;
        }
        if(i == xmax+1 && v[i]-v[l-1]) ans++;
    }
    cout << ans << "\n";
    return 0;
}
