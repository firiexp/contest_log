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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n+1, vector<int>(n+1, 0));
    auto ans = v;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            v[i][j] = (s[j] == 'B');
        }
    }
    for (int i = 0; i < n; ++i) {
        int l = n+1, r = -1;
        for (int j = 0; j < n; ++j) {
            if(v[i][j]) l = min(l, j), r = max(r, j);
        }
        if(r-l > k) continue;
        if(l > r) ans[0][0]++;
        else {
            ans[i+1][l+1]++;
            ans[max(0, i-k+1)][l+1]--;
            ans[i+1][max(0, r-k+1)]--;
            ans[max(0, i-k+1)][max(0, r-k+1)]++;
        }
    }
    for (int j = 0; j < n; ++j) {
        int l = n+1, r = -1;
        for (int i = 0; i < n; ++i) {
            if(v[i][j]) l = min(l, i), r = max(r, i);
        }
        if(r-l > k) continue;
        if(l > r) ans[0][0]++;
        else {
            ans[l+1][j+1]++;
            ans[l+1][max(0, j-k+1)]--;
            ans[max(0, r-k+1)][j+1]--;
            ans[max(0, r-k+1)][max(0, j-k+1)]++;
        }
    }
    int X = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            ans[i][j] += ans[i-1][j];
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans[i][j] += ans[i][j-1];
        }
    }
    for (auto &&i : ans) {
        X = max(X, *max_element(i.begin(),i.end()));
    }
    cout << X << "\n";
    return 0;
}