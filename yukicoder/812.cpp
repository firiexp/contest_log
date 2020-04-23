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
    vector<vector<int>> v(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        queue<int> s;
        vector<int> visited(n), ans(n);
        s.emplace(a-1);
        int p = 0;
        visited[a-1]++;
        while(!s.empty()){
            int x = s.front(); s.pop();
            for (auto &&i : v[x]) {
                if(!visited[i]) {
                    visited[i]++;
                    s.emplace(i);
                    ans[i] = ans[x]+1;
                    p++;
                }
            }
        }
        int anss = 0, mans = *max_element(ans.begin(),ans.end());
        while(1<<anss < mans) anss++;
        cout << p << " " << anss << "\n";
    }
    return 0;
}