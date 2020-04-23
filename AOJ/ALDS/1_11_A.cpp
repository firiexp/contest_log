#include <iostream>
using ll = long long;
using namespace std;
/* initialize */

/* main */
int main() {
    int n,u,k, v;
    int A[100][100];
    cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) A[i][j] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            cin >> v;
            A[u-1][v-1] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            cout << A[i][j] << " ";
        }
        cout << A[i][n-1] << "\n";
    }
    return 0;
}