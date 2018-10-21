#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
static const int MOD = 1000000007;

int main() {
    int n, s, k;
    cin >> n >> s >> k;
    int minsum = k * n * (n-1) / 2;
    if(minsum > s) {
        cout << 0 << "\n";
        return 0;
    }
    vector<vector<int>> v(2, vector<int>(20001, 0));
    v[0][0] = 1;
    s = s - minsum;
    for (int i = 1; i <= n; ++i) {
        int now = i % 2, prv = now^1;
        v[now].assign(v[now].size(), 0);
        for (int j = 0; j <= s; ++j) {
            if(j >= i){
                v[now][j] = (v[prv][j] + v[now][j-i]) % MOD;
            }else {
                v[now][j] = v[prv][j];
            }
        }
    }
    cout << v[n%2][s];
    return 0;
}
