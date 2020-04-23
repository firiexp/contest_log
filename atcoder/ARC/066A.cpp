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
    int n;
    cin >> n;
    map<int, int> v;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        v[k]++;
    }
    if(n%2 == 0){
        for (int i = 0; i < n/2; ++i) {
            if(v[i*2+1] != 2){
                cout << 0 << "\n";
                return 0;
            }
        }

    }else {
        if(v[0] != 1){
            cout << 0 << "\n";
            return 0;
        }
        for (int i = 1; i <= n/2; ++i) {
            if (v[i*2] != 2){
                cout << 0 << "\n";
                return 0;
            }
        }
    }
    cout << pow_(2, n/2, INF) << "\n";
    return 0;
}
