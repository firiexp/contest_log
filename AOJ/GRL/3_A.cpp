#include <iostream>
#include <vector>
#include <set>

using ll = long long;
using namespace std;

vector<int> G[100000];
int N;
bool visited[100000] = {};
int prenum[100000], parent[100000], lowest[100000], timer;
void dfs ( int now, int prev){
    prenum[now] = lowest[now] = timer;
    timer++;
    visited[now] = true;

    for (int &next : G[now]){
        if (!visited[next]){
            parent[next] = now;
            dfs(next, now);
            lowest[now] = min(lowest[now], lowest[next]);
        } else if (next != prev){
            lowest[now] = min(lowest[now], prenum[next]);
        }
    }
}

void artpoints(){
    for (int j = 0; j < N; ++j) {
        visited[j] = false;
    }
    timer = 1;
    dfs(0, -1);

    set<int> ap;
    int np = 0;
    for (int i = 0; i < N; ++i) {
        int p = parent[i];
        if (p == 0) np++;
        else if (prenum[p] <= lowest[i]) ap.insert(p);
    }
    if (np > 2) ap.insert(0);
    for (auto &a: ap){
        cout << a << "\n";
    }
}

int main() {
    int m;
    cin >> N >> m;
    for (int i = 0; i < m; ++i) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    artpoints();
    return 0;
}
