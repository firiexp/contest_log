#include <iostream>
#include <vector>
#include <queue>
#include <list>

using ll = long long;
using namespace std;

vector<int> G[1000000];
int indeg[1000000] = {};
int N;
bool V[1000000];
list<int> out;
void bfs(int s) {
    queue<int> q;
    q.push(s);
    V[s] = true;
    while (!q.empty()){
        int u = q.front(); q.pop();
        out.push_back(u);
        for (int v : G[u]) {
            indeg[v]--;
            if (indeg[v] == 0 && !V[v]) {V[v] = true; q.push(v);}
        }
    }
}

void toporogicalsort() {
    for (int i = 0; i < N; ++i) {
        for (int v : G[i]) {
            indeg[v]++;
        }
    }
    for (int u = 0; u < N; ++u) {
        if ( indeg[u] == 0 && !V[u]) bfs(u);
    }
    for (int &it : out) {
        cout << it << "\n";
    }
}



int main() {
    int s, t, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        V[i] = false;
    }

    for (int i = 0; i < M; ++i) {
        cin >> s >> t;
        G[s].push_back(t);
    }

    toporogicalsort();
    return 0;

}