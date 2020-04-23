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

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; ++i) {
        int a, b, c, d, e, f;
        scanf("%d %d:%d %d %d:%d", &a, &b, &c, &d, &e, &f);
        v[i] = {d*1440+e*60+f+1, a*1440+b*60+c};
    }
    sort(v.begin(),v.end());
    vector<int> time(n);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(time[j] <= v[i].second){
                time[j] = v[i].first;
                ans++;
                break;
            }
        }
        sort(time.begin(),time.end(), greater<>());
    }
    cout << ans << "\n";
    return 0;
}