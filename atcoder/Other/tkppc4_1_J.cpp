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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&j : b) scanf("%d", &j);
    vector<ll> X(1<<n), Y(1<<m);
    for (int i = 0; i < (1<<n); ++i) {
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)){
                X[i] = X[i^(1<<j)]+a[j];
                break;
            }
        }
    }
    for (int i = 0; i < (1<<m); ++i) {
        for (int j = 0; j < m; ++j) {
            if(i & (1 << j)){
                Y[i] = Y[i^(1<<j)]+b[j];
                break;
            }
        }
    }
    ll S = X.back(), T = Y.back();
    if(S - T <= 0) {
        puts("0");
        return 0;
    }
    vector<ll> A, B;
    for (auto &&i : X) if(i*2 > S && S != i) A.emplace_back(i);
    for (auto &&i : Y) if(i*2 > T && T != i) B.emplace_back(i);
    B.emplace_back(INF<ll>);
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int l = 0, r = 0;
    int ans = 0;
    for (auto &&i : A) {
        while(T-S+i >= B[l]) l++;
        while(i > B[r]) r++;
        ans = max(ans, r-l);
    }
    printf("%.10lf\n", (double)ans/((int)B.size()-1));
    return 0;
}