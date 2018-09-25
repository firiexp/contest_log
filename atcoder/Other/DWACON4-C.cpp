#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <deque>

const int MOD = 1000000007;
using ll = long long;
using namespace std;
vector<vector<ll>> part(201, vector<ll>(1001, 0));
using P = pair<int, int>;

ll perms(vector<int> &k1, int k){
    deque<P> d;
    d.emplace_back(k1[0], 1);
    for (int i = 1; i < k1.size(); ++i) {
        if(d.back().first == k1[i]) d.back().second++;
        else d.emplace_back(k1[i], 1);
    }
    vector<vector<ll>> dp(d.size() + 1, vector<ll>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < d.size(); ++i) {
        for (int j = 0; j < k + 1; ++j) {
            for (int l = 0; l < k - j + 1; ++l) {
                dp[i+1][j + l] = (dp[i+1][j+l] + ((ll)dp[i][j] * part[d[i].second][l]) % MOD ) % MOD;
            }
        }
    }
    return dp[d.size()][k];
}

int main() {
    unsigned int n, m;
    cin >> n >> m;
    part[0][0] = 1;
    for (int i = 1; i <= 200; ++i) {
        int now = i, prv = now-1;
        part[now].assign(1001, 0);
        for (int j = 0; j <= 1000; ++j) {
            if(j >= i) part[now][j] = (part[prv][j] + part[now][j-i]) % MOD;
            else part[now][j] = part[prv][j];
        }
    }
    vector<int> Ka(n), Kb(m);
    for (int i = 0; i < n; ++i) {
        cin >> Ka[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> Kb[i];
    }
    int ka = accumulate(Ka.begin(), Ka.end(), 0), kb = accumulate(Kb.begin(), Kb.end(), 0);
    cout << (perms(Ka, kb) * perms(Kb, ka) ) % MOD << "\n";
    return 0;
}
