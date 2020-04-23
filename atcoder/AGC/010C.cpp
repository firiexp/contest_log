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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int main() {
    int n;
    cin >> n;
    vector<ll> v(n), v2(n);
    for (int i = 0; i < n; ++i) {
        scanf("%li", &v[i]);
    }
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a-1].emplace_back(b-1);
        G[b-1].emplace_back(a-1);
    }
    deque<int> Q;
    vector<int> num(n);
    {
        stack<int> s;
        int cnt = 0;
        vector<int> visited(n, 0);
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
    }
    while(!Q.empty()){
        int i = Q.front(); Q.pop_front();
        int cnt = 0;
        ll m = -INF<ll>, sum = 0;
        for (auto &&j : G[i]) {
            if(num[i] < num[j]) {
                sum += v2[j];
                m = max(m, v2[j]);
                cnt++;
            }
        }
        if(cnt == 0 || m == -INF<ll>) {
            v2[i] = v[i];
            continue;
        }
        ll M = min((sum-m), sum/2);
        ll x = sum-v[i];
        if(x < 0 || x > M){
            puts("NO");
            return 0;
        }
        v2[i] = sum - x*2;
    }
    if(G[0].size() != 1 && v2[0] != 0){
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}
