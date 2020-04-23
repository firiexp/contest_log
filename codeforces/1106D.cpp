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

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;


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
    vector<int> visited(n);
    visited[0] = 1;
    GPQ<int> Q;
    Q.emplace(0);
    vector<int> ans;
    while(!Q.empty()){
        int i = Q.top(); Q.pop();
        ans.emplace_back(i);
        for (auto &&j : v[i]) {
            if(!visited[j]){
                Q.emplace(j);
                visited[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]+1);
    }
    puts("");
    return 0;
}