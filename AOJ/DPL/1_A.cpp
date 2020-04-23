#include <iostream>
using ll = long long;
using namespace std;
static const int INF = (1 << 29);

int main() {
    int n, m;
    int C[21];
    int T[50001];

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> C[i];
    }

    for (int j = 0; j <= 50000; ++j) T[j] = INF;
    T[0] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j + C[i] <= n; ++j) {
            T[j + C[i]] = min(T[j+C[i]], T[j]+1);
        }
    }

    cout << T[n] << "\n";
    return 0;
}
