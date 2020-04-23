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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v(n);
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[i] = x;
        p.emplace_back(x, i);
    }
    sort(p.begin(), p.end());
    queue<pair<int, int>> Q;
    Q.emplace(0, n-1);
    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        int sz = static_cast<int>(Q.size());
        int num, id;
        tie(num, id) = p[i];
        vector<int> mn;
        for (int j = 0; j < sz; ++j) {
            int a, b;
            tie(a, b) = Q.front(); Q.pop();
            if(a > b) continue;
            vector<int> u;
            for (int l = a; l <= b; ++l) {
                u.emplace_back(v[l]);
            }
            sort(u.begin(), u.end());
            for (int l = 0; l < (ll)b-a-k+2; ++l) {
                mn.emplace_back(u[l]);
            }
            if(a <= id && id <= b){
                Q.emplace(a, id-1);
                Q.emplace(id+1, b);
            }else Q.emplace(a, b);
        }
        if(mn.size() < q) break;
        sort(mn.begin(), mn.end());
        ans = min(ans, mn[q-1]-mn[0]);
    }
    cout << ans << "\n";
    return 0;
}
