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

int main() {
    int n;
    cin >> n;
    string S;
    cin >> S;
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    vector<int> cs(n), ws(n);
    ll csum = 0, wsum = 0;
    for (int i = 0; i < n; ++i) {
        if(S[i] == 'c') cs[i]++, csum++;
        else ws[i]++, wsum++;
    }
    ll ans = csum*wsum*(wsum-1);
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
    for (auto &&i : Q) {
        for (auto &&j : G[i]) {
            if(num[i] < num[j]){
                 cs[i] += cs[j];
                 ws[i] += ws[j];
            }
        }
    }
    for (auto &&i : Q) {
        if(S[i] == 'w'){
            ans -= (csum-cs[i])*(wsum-ws[i]);
            for (auto &&j : G[i]) {
                if(num[i] < num[j]){
                    ans -= (ll)cs[j]*ws[j];
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}