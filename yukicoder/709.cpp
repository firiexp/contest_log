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
    vector<int> cnt(n);
    vector<queue<pair<int, int>>> qs(m);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            scanf("%d", &x);
            if(qs[j].empty() || qs[j].front().first <= x) {
                qs[j].emplace(x, i);
                cnt[i]++;
                if(cnt[i] == 1) ans++;
            }
            while(qs[j].front().first < x) {
                cnt[qs[j].front().second]--;
                if(cnt[qs[j].front().second] == 0) ans--;
                qs[j].pop();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}