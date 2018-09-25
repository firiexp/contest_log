#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

ll pow_ (ll x, ll n, ll M){
    ll u = 1;
    if(n > 0){
        u = pow_(x, n/2, M);
        if (n % 2 == 0) u = (u*u) % M;
        else u = (((u * u)% M) * x) % M;
    }
    return u;
};

int main() {
    int x;
    cin >> x;
    vector<int> v;
    for (int j = 1; j <= 31; ++j) {
        for (int i = 2; i <= 9; ++i) {
            ll k = pow_(j, i, (ll)INF*INF);
            if(k > 1000) break;
            v.emplace_back(k);
        }
    }
    sort(v.begin(), v.end(), greater<>());
    cout << *lower_bound(v.begin(), v.end(), x, greater<>()) << "\n";
    return 0;
}
