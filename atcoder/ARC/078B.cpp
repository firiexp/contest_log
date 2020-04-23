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
    vector<vector<int>> v(n);
    vector<int> visited(n, 0), d(n, INF<int>), d2(n, INF<int>);
    visited[0] = 1;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        v[a-1].emplace_back(b-1);
        v[b-1].emplace_back(a-1);
    }
    stack<pair<int, int>> S;
    S.emplace(0, 0);
    d[0] = 0;
    while(!S.empty()){
        auto p = S.top(); S.pop();
        for (auto &&i : v[p.first]) {
            if(!visited[i]){
                visited[i] = 1;
                d[i] = p.second+1;
                S.emplace(i, p.second+1);
            }
        }
    }
    S.emplace(n-1, 0);
    visited[n-1] = 1;
    d2[n-1] = 0;
    fill(visited.begin(), visited.end(), 0);
    while(!S.empty()){
        auto p = S.top(); S.pop();
        for (auto &&i : v[p.first]) {
            if(!visited[i]){
                visited[i] = 1;
                d2[i] = p.second+1;
                S.emplace(i, p.second+1);
            }
        }
    }
    int p = 0, q = 0;
    for (int j = 1; j < n-1; ++j) {
        if(d[j] <= d2[j]) p++;
        else q++;
    }
    cout << (p <= q ? "Snuke" : "Fennec") << "\n";
    return 0;
}
