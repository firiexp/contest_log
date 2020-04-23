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
    int h, w, d;
    cin >> h >> w >> d;
    using P = pair<int, int>;
    vector<P> v((u32)(h * w + 1), P{0, 0});
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int x;
            scanf("%d", &x);
            v[x] = {i, j};
        }
    }
    vector<int> dp((u32)(h*w+1), 0);
    for (int i = 1; i <= h*w; ++i) {
        if(i-d>0) dp[i] = dp[i-d] + abs(v[i].first-v[i-d].first)+abs(v[i].second-v[i-d].second);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        cout << dp[r]-dp[l] << "\n";
    }
    return 0;
}
