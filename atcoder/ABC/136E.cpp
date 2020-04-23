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

static const int MOD = 998244353;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<class T>
vector<T> divisor(T n){
    vector<T> ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret), greater<>());
    return(ret);
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    ll s = accumulate(v.begin(),v.end(), 0LL);
    auto div = divisor(s);
    for (auto &&x : div) {
        vector<int> u(n);
        for (int i = 0; i < n; ++i) u[i] = v[i]%x;
        sort(u.begin(),u.end());
        vector<int> A(n+1), B(n+1);
        for (int i = 0; i < n; ++i) {
            A[i+1] = A[i] + u[i];
        }
        for (int j = n-1; j >= 0; --j) {
            B[j] = B[j+1] + (x-u[j]);
        }
        for (int i = 0; i <= n; ++i) {
            if(A[i]%x == B[i]%x && max(A[i], B[i]) <= k){
                cout << x << "\n";
                return 0;
            }
        }
    }
    return 0;
}