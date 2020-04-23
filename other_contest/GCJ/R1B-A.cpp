#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


void solve(){
    int p, q;
    cin >> p >> q;
    vector<int> xs(p), ys(p); vector<char> cs(p);
    vector<int> x{0, q}, y{0, q};
    for (int i = 0; i < p; ++i) {
        cin >> xs[i] >> ys[i] >> cs[i];
        if(cs[i] == 'N') y.emplace_back(ys[i]+1);
        if(cs[i] == 'S') y.emplace_back(ys[i]);
        if(cs[i] == 'E') x.emplace_back(xs[i]+1);
        if(cs[i] == 'W') x.emplace_back(xs[i]);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    vector<vector<int>> g(x.size(), vector<int>(y.size()));
    for (int i = 0; i < p; ++i) {
        if(cs[i] == 'N'){
            g[0][lower_bound(y.begin(),y.end(), ys[i]+1)- y.begin()]++;
        } else if(cs[i] == 'E'){
            g[lower_bound(x.begin(),x.end(), xs[i]+1)- x.begin()][0]++;
        }else if(cs[i] == 'S') {
            g[0][0]++;
            g[0][lower_bound(y.begin(),y.end(), ys[i])- y.begin()]--;
        }else if(cs[i] == 'W'){
            g[0][0]++;
            g[lower_bound(x.begin(),x.end(), xs[i])- x.begin()][0]--;
        }
    }

    for (int i = 1; i < x.size(); ++i) {
        for (int j = 0; j < y.size(); ++j) {
            g[i][j] += g[i-1][j];
        }
    }
    for (int i = 0; i < x.size(); ++i) {
        for (int j = 1; j < y.size(); ++j) {
            g[i][j] += g[i][j-1];
        }
    }
    int m = 0;
    for (int i = 0; i < x.size(); ++i) {
        for (int j = 0; j < y.size(); ++j) {
            m = max(m, g[i][j]);
        }
    }
    for (int i = 0; i < x.size(); ++i) {
        for (int j = 0; j < y.size(); ++j) {
            if(m == g[i][j]){
                cout << x[i] << " " << y[j] << "\n";
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
