#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    vector<ll> v;
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        v.emplace_back(x);
    }
    sort(v.begin(), v.end(), greater<>());
    ll sum = 0;
    vector<vector<ll>> comb(n+1, vector<ll>(n+1, 0));
    for (int i = 0; i < n+1; ++i) comb[i][0] = comb[i][i] = 1;
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < i; ++j) {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
    int p=0,q=0;
    for(int i = 0; i < n; ++i){
        if(v[i]==v[a-1]){
            p++;
            if(i < a){
                q++;
            }
        }
    }

    if(q != a){
        sum = comb[p][q];
    }else {
        for (int i = a; i <= b; ++i) {
            sum += comb[p][i];
        }
    }
    double ans = accumulate(v.begin(), v.begin()+a, 0.0)/a;
    printf("%.6f\n", ans);
    cout << sum << "\n";
    return 0;
}
