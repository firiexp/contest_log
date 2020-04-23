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
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    deque<int> Q;
    stack<int> s;
    int cnt = 0;
    vector<int> visited(n, 0), num(n);
    s.emplace(0);
    while(!s.empty()){
        int a = s.top(); s.pop();
        visited[a]++;
        num[a] = cnt++;
        Q.emplace_front(a);
        for (auto &&i : G[a]) {
            if(!visited[i]) s.emplace(i);
        }
    }
    vector<int> dp1(n), dp2(n, 1);
    for (auto &&i : Q) {
        int c = 0;
        for (auto &&j : G[i]) {
            if(num[i] < num[j]){
                c++;
                dp1[i] += max(dp1[j], dp2[j]);
                dp2[i] += max(dp1[j], dp2[j]-1);
            }
        }
    }
    cout << max(dp1.front(), dp2.front()) << "\n";
    return 0;
}