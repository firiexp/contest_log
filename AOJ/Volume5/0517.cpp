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
    int n, k;
    while (cin >> n >> k, n|k){
        map<int, int> m;
        vector<pair<int, int>> c;
        for (int i = 0; i < k; ++i) {
            int x;
            scanf("%d", &x);
            m[x]++;
        }
        int w = m[0];
        int s = 0, g = 0, ans = 1;
        for (int i = 1; i <= n+1; ++i) {
            if(m[i]) {
                if(s == 0) s = i;
                g = i;
            }
            else  {
                if(s != 0 && g != 0) {
                    ans = max(ans, w+g-s+1);
                    c.emplace_back(s, g);
                }
                s = 0, g = 0;
            }
        }
        if(w) {
            for (int i = 0; i < c.size()-1; ++i) {
                if(c[i+1].first-c[i].second == 2){
                    ans = max(ans, c[i+1].second-c[i].first+1);
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
