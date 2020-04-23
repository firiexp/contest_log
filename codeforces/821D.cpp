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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v(k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(), v.end());
    deque<int> Q;
    vector<int> dist(k, INF<int>);
    dist[0] = 0;
    Q.emplace_back(0);
    while(!Q.empty()){
        int x = Q.front(); Q.pop_front();
        for (int y = 0; y < k; ++y) {
            if(x == y) continue;
            if(abs(v[x].first-v[y].first)+abs(v[x].second-v[y].second) == 1){
                if(dist[x] < dist[y]){
                    dist[y] = dist[x];
                    Q.emplace_front(y);
                }
            }else if(abs(v[x].first-v[y].first) <= 2 || abs(v[x].second-v[y].second)<= 2){
                if(dist[x]+1 < dist[y]){
                    dist[y] = dist[x]+1;
                    Q.emplace_back(y);
                }
            }
        }
    }
    int ans = INF<int>;
    for (int i = 0; i < k; ++i) {
        if(v[i].first == n && v[i].second == m){
            ans = min(ans, dist[i]);
        }else if(abs(v[i].first-n) <= 1 || abs(v[i].second-m) <= 1){
            ans = min(ans, dist[i]+1);
        }
    }
    cout << (ans == INF<int> ? -1 : ans) << "\n";
    return 0;
}