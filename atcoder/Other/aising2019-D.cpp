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
    int n, q;
    cin >> n >> q;
    vector<ll> v(n), s(n+1, 0), s2(n+1, 0);
    for (auto &&i : v) scanf("%lld", &i);
    for (int i = 0; i < n; ++i) {
        if(i == 0) s2[1] = v[i];
        else s2[i+1] = s2[i-1] + v[i];
        s[i+1] = s[i]+v[i];
    }
    for (int i = 0; i < q; ++i) {
        int X;
        scanf("%d", &X);
        int low = 0, high = n;
        while(high-low > 1){
            int mid = (low+high)/2;
            if(v[mid-1] < X) low = mid;
            else {
                int tak = n-mid;
                int ao = mid - (lower_bound(v.begin(), v.end(), max(1LL, 2*X-v[mid-1]))- v.begin());
                (tak < ao ? high : low) = mid;
            }
        }
        ll ans = s[n]-s[low];
        if(2*low >= n) ans += s2[2*low-n];
        printf("%lld\n", ans);
    }
    return 0;
}
