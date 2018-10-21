#include <iostream>
using ll = long long;
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
    ll x, N, a, sum = 0;
    cin >> x >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        sum = (sum +  pow_(x, a, 1000003))% 1000003;
    }
    cout << sum;
    return 0;
}