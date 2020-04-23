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
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int h, m, s, c, c2;
    cin >> h >> m >> s >> c >> c2;
    h %= 12;
    int t = h*3600+m*60+s, dt = 0;
    int ans1 = -1, ans2 = INF<int>;
    while (true){
        ll h2 = t, m2 = t%3600*12, s2 = t%60*12*60;
        t++;
        dt++;
        ll h3 = h2+1, m3 = m2+12, s3 = s2+12*60;
        if(s2 <= m2 && s3 > m3) c--;
        if(m2 <= h2 && m3 > h3) c2--;
        if(c == 0 && c2 == 0 && (m3 % (12*60*60) != s3 % (12*60*60))
                     && (m3 % (12*60*60) != h3 % (12*60*60))){
            ans1 = max(ans1 ,dt);
            ans2 = min(ans2, dt);
        }
        if(c < 0 || c2 < 0) break;
        t %= (3600*12);
    }
    if(ans1 < 0) cout << -1 << "\n";
    else cout << ans2 << " " << ans1 << "\n";
    return 0;
}
