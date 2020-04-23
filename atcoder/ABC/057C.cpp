#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            if (i * i != n) ret.emplace_back(max(i, n/i));
            else ret.emplace_back(i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> v = divisor(n);
    cout << to_string(v.front()).length() << "\n";
    return 0;
}
