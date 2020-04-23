#include <iostream>
#include <stack>
#include <vector>

using ll = long long;
using namespace std;
using p = pair<int, int>;
static const int INF = 10000000;

int main() {
    int n, m;
    int visited[100];
    int last = -1;
    vector<vector<int> > gr;
    stack<p> S;
    gr.resize(100);
    fill_n(&visited[0], 100, 0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        gr[u-1].emplace_back(v-1);
        gr[v-1].emplace_back(u-1);
    }
    S.push({0, -1});
    int c = 1;
    while (!S.empty()) {
        int last2 = S.top().second; last = S.top().first;
        S.pop();

        for (int &a: gr[last]) {
            if(a != last && a != last2) S.push({a, last});
        }
        if(visited[last]){
            S = stack<p>();
            c--;
        }
        visited[last] = 1;
        if(S.empty()) {
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    S.push({i, -1}); c++; break;
                }
            }
        }
    }
    cout << c << "\n";
    return 0;
}
