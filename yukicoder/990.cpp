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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    char c;
    cin >> c;
    vector<ll> v(n), u(m);
    for (auto &&i : u) scanf("%lld", &i);
    for (auto &&j : v) scanf("%lld", &j);
    ll ans = 0;
    if(c == '+'){
        map<int, int> A;
        for (int i = 0; i < m; ++i) {
            A[u[i]%k]++;
        }
        for (int i = 0; i < n; ++i) {
            ans += A[(-v[i]%k+k)%k];
        }
    }else {
        map<ll, ll> A, B;
        for (int i = 0; i < m; ++i) {
            A[__gcd(u[i], k)]++;
        }
        for (int i = 0; i < n; ++i) {
            B[__gcd(v[i], k)]++;
        }
        for (auto &&i : A) {
            for (auto &&j : B) {
                if((ll)i.first*j.first%k == 0){
                    ans += i.second*j.second;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}