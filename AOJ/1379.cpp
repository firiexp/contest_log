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

vector<int> x, y;
vector<pair<int, int>> u;
int n;
int dfs(vector<int> &v, int depth = 1){
    if(n-(depth-1)*2 < 1) {
        int ret = 0;
        for (int i = 0; i < u.size(); ++i) {
            for (int j = i+1; j < u.size(); ++j) {
                if(u[i].first*u[j].second == u[j].first*u[i].second) ret++;
            }
        }
        return ret;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i]) continue;
        for (int j = i+1; j < n; ++j) {
            if(v[j]) continue;
            int tmp1 = v[i], tmp2 = v[j];
            v[i] = v[j] = depth;
            u.emplace_back(x[i]-x[j], y[i]-y[j]);
            ans = max(ans, dfs(v, depth+1));
            u.pop_back();
            v[i] = tmp1; v[j] = tmp2;
        }
        break;
    }
    return ans;
}

int main() {
    cin >> n;
    x.resize(n); y.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<int> v(n);
    cout << dfs(v) << "\n";
    return 0;
}