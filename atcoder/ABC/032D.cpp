#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using ll = long long;
using namespace std;
static const ll INF = 1000000000000000;
static const ll INF2 = 2000000000;
array<array<ll, 200001>, 2> dp{};

int main() {
    int n, w, maxv=0, maxw=0;
    array<int, 1000> vv{}, ww{};
    fill_n(&vv[0], 1000, 0);
    fill_n(&vv[0], 1000, 0);
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
        cin >> vv[i] >> ww[i];
        maxv = max(maxv, vv[i]);
        maxw = max(maxw, ww[i]);
    }
    if (n <= 30){
        array<pair<ll, ll>, (1 << 15)> ps;
        fill(ps.begin(), ps.end(), make_pair(INF, 0));
        int n2 = n/2;
        for (int i = 0; i < (1 << n2); ++i) {
            ll sw = 0, sv = 0;
            for (int j = 0; j < n2; ++j) {
                if (i & (1<<j)) {
                    sw += ww[j];
                    sv += vv[j];
                }
            }
            ps[i] = make_pair(sw, sv);
        }
        sort(ps.begin(), ps.end());
        int m = 1;
        for (int i = 1; i < (1 << n2); ++i) {
            if (ps[m-1].second < ps[i].second){
                ps[m++] = ps[i];
            }
        }
        ll res = 0;
        for (int i = 0; i < (1 << (n-n2)); ++i) {
            ll sw = 0, sv = 0;
            for (int j = 0; j < n-n2; ++j) {
                if (i & (1<<j)) {
                    sw += ww[n2+j];
                    sv += vv[n2+j];
                }
                if(sw <= w){
                    ll tv = (lower_bound(ps.begin(), ps.end(), make_pair(w-sw, (INF)))-1)->second;
                    res = max(res, tv + sv);
                }
            }
        }
        cout << res << "\n";
    }else if (maxv <= 1000) {
        int ans = 0;

        fill_n(&dp[0][1], 200000, INF);
        for (int i = 0; i < n; ++i) {
            int now = i % 2, nex = (i+1)%2;
            fill_n(&dp[nex][0], 200001, 0);
            for (int j = 0; j < 200002; ++j) {
                if (j < vv[i]){
                    dp[nex][j] = dp[now][j];
                }else {
                    dp[nex][j] = min(dp[now][j], dp[now][j-vv[i]]+ww[i]);
                }
            }
        }
        for (int i = 0; i < 200000; ++i) {
            if (dp[n%2][i] <= w) ans = i;
        }
        cout << ans << "\n";
    }else {
        for (int i = 0; i < n; ++i) {
            int now = i % 2, nex = (i+1)%2;
            fill_n(&dp[nex][0], 200001, 0);
            for (int j = 0; j < 200002; ++j) {
                if (j < ww[i]){
                    dp[nex][j] = dp[now][j];
                }else {
                    dp[nex][j] = max(dp[now][j], dp[now][j-ww[i]]+vv[i]);
                }
            }
        }
        cout << dp[n%2][w] << "\n";
    }
    return 0;
}
