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
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            v[i][j] = (s[j]-'0' ? 1 : INF<int>);
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
            }
        }
    }
    int m;
    cin >> m;
    vector<int> u(m);
    for (auto &&i : u) scanf("%d", &i), i--;
    vector<int> ans;
    ans.emplace_back(0);
    for (int i = 1; i < m; ++i) {
        while( ans.size() != 1 && v[u[ans.size()-2]][u[i]] == i-ans.back()+1) ans.pop_back();
        ans.emplace_back(i);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        if(i) printf(" ");
        printf("%d", u[ans[i]]+1);
    }
    puts("");
    return 0;
}