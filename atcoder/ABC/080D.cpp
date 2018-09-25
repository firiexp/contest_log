#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;
using P = pair<int, int>;

int main() {
    int n, c;
    cin >> n >> c;
    vector<GPQ<P>> v(c), v2(c);
    for (int i = 0; i < n; ++i) {
        int ss, tt, cc;
        scanf("%d%d%d", &ss, &tt, &cc);
        v[cc-1].emplace(ss, tt);
    }
    vector<int> imos(100001, 0);
    for (auto &Q: v) {
        P p;
        if(!Q.empty()) {
            p = Q.top(); Q.pop();
            if(Q.empty()) {
                imos[p.first-1]++; imos[p.second]--;
            }
        }
        while (!Q.empty()){
            P p2 = Q.top(); Q.pop();
            if(p.second == p2.first) {
                p.second = p2.second;
                if(Q.empty()){
                    imos[p.first-1]++; imos[p.second]--;
                }
            }
            else{
                imos[p.first-1]++; imos[p.second]--;
                p = p2;
            }
        }
    }
    int sum = 0, ans = 0;
    for (int i = 0; i < 100001; ++i) {
        sum += imos[i];
        ans = max(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}
