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

void solve(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    vector<int> A(a), B(b), C(c);
    for (auto &&i : A) scanf("%d", &i);
    for (auto &&j : B) scanf("%d", &j);
    for (auto &&k : C) scanf("%d", &k);
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    ll ans = INF<ll>;
    auto f = [](ll a, ll b, ll c){ return (a-b)*(a-b)+(b-c)*(b-c)+(c-a)*(c-a); };
    for (int i = 0; i < a; ++i) {
        int x = lower_bound(B.begin(),B.end(), A[i]) - B.begin();
        int y = lower_bound(C.begin(),C.end(), A[i]) - C.begin();
        for (int j = max(0, x-2); j < min(b, x+2); ++j) {
            for (int k = max(0, y-2); k < min(c, y+2); ++k) {
                ans = min(ans, f(A[i], B[j], C[k]));
            }
        }
    }
    swap(A, B);
    swap(a, b);
    for (int i = 0; i < a; ++i) {
        int x = lower_bound(B.begin(),B.end(), A[i]) - B.begin();
        int y = lower_bound(C.begin(),C.end(), A[i]) - C.begin();
        for (int j = max(0, x-2); j < min(b, x+2); ++j) {
            for (int k = max(0, y-2); k < min(c, y+2); ++k) {
                ans = min(ans, f(A[i], B[j], C[k]));
            }
        }
    }
    swap(A, C);
    swap(a, c);
    for (int i = 0; i < a; ++i) {
        int x = lower_bound(B.begin(),B.end(), A[i]) - B.begin();
        int y = lower_bound(C.begin(),C.end(), A[i]) - C.begin();
        for (int j = max(0, x-2); j < min(b, x+2); ++j) {
            for (int k = max(0, y-2); k < min(c, y+2); ++k) {
                ans = min(ans, f(A[i], B[j], C[k]));
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}