#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int minus = 0, plus = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] < 0) minus++;
        else plus++;
    }
    sort(v.begin(),v.end());
    if(minus == n) minus--, plus++;
    if(plus == n) plus--, minus++;
    vector<int> P, M, A;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(i < minus) {
            M.emplace_back(v[i]);
            ans += -v[i];
        } else {
            P.emplace_back(v[i]);
            ans += v[i];
        }
    }
    cout << ans << "\n";
    ll k = M[0];
    for (int i = 0; i < plus-1; ++i) {
        cout << k << " " << P[i] << "\n";
        k -= P[i];
    }
    cout << P[plus-1] << " " << k << "\n";
    k = P[plus-1]-k;
    for (int i = 0; i < minus-1; ++i) {
        cout << k << " " << M[i+1] << "\n";
        k -= M[i+1];
    }
    return 0;
}