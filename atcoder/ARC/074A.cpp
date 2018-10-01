#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    ll h, w;
    cin >> h >> w;
    if(h*w % 3 == 0){
        cout << 0 << "\n";
        return 0;
    }
    ll ans = INF<ll>;
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < h; ++j) {
            ll s1 = j*w;
            ll s2 = (h-j)*(w/2);
            ll s3 = h*w- (s1+s2);
            ans = min(ans, max({s1, s2, s3})- min({s1, s2, s3}));
        }
        for (int j = 1; j < h; ++j) {
            ll s1 = j*w;
            ll s2 = (h-j)/2*w;
            ll s3 = h*w- (s1+s2);
            ans = min(ans, max({s1, s2, s3})- min({s1, s2, s3}));
        }
        swap(h,w);
    }
    cout << ans << "\n";
    return 0;

}
