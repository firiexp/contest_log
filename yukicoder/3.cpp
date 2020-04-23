#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;



int main() {
    int n;
    cin >> n;
    vector<int> d(n, INF<int>);
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        int k = __builtin_popcount(i+1);
        if(i > k) {
            v[i].emplace_back(i-k);
        }
        if(i+k < n){
            v[i].emplace_back(i+k);
        }
    }
    stack<pair<int,int>> Q;
    Q.emplace(0, 1);
    while(!Q.empty()){
        int x, c;
        tie(x, c) = Q.top(); Q.pop();
        d[x] = c;
        for (auto &&i : v[x]) {
            if(c+1 < d[i]){
                Q.emplace(i, c+1);
            }
        }
    }
    cout << (d[n-1] == INF<int> ? -1 : d[n-1]) << "\n";
    return 0;
}
