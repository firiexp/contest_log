#include <iostream>
using ll = long long;
using namespace std;
static const int INF = 1000000000;

int main() {
    int N, M, L, X;
    cin >> N >> M >> L >> X;
    int dp[2][1000];
    fill_n(&dp[0][0], 2000, INF);
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        int now = i%2, prv = now^1;
        int a;
        cin >> a;
        fill_n(&dp[now][0], 1000, INF);
        for (int j = 0; j < M; ++j) {
            if(dp[prv][j] == INF)continue;
            dp[now][(j+a)%M] = min(dp[prv][j]+(j+a)/M, dp[now][(j+a)%M]);
        }
        for (int j = 0; j < M; ++j) {
            dp[now][j] = min(dp[prv][j], dp[now][j]);
        }
    }
    cout << (dp[N%2][L] < X ? "Yes" : "No") << "\n";
    return 0;
}
