#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using ll = long long;
using namespace std;

int main() {
    int n, m, c = 0;
    cin >> n >> m;
    int v[n][n];
    fill_n(*v, n*n, 0);
    vector<int> V(n);
    iota(V.begin(), V.end(), 0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a-1][b-1] = 1; v[b-1][a-1] = 1;
    }
    do {
        int f = 1;
        for (int i = 0; i < n-1; ++i) {
            if(!v[V[i]][V[i+1]]) {f = 0; break;}
        }
        c += f;
    } while (next_permutation(V.begin()+1, V.end()));
    cout << c << "\n";
    return 0;
}
