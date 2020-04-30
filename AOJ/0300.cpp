#include <iostream>
#include <algorithm>
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
    using P = array<int, 30>;
    P X;
    for (auto &&i : X) scanf("%d", &i);
    vector<P> ok{};
    vector<array<int, 10>> shifts{{0, 3, 6, 9, 15, 23, 26, 29, 20, 17}, {2, 5, 8, 11, 12, 21, 24, 27, 18, 14},
                                 {0, 1, 2, 14, 18, 27, 28, 29, 15, 20}, {6, 7, 8, 12, 9, 21, 22, 23, 17, 11}};
    int ans = 8;
    auto dfs = [&](int dep, P A, auto &&f) -> void {
        if(dep >= ans) return;
        int ok = 1;
        for (int i = 0; i < 8 && ok; ++i) {
            if(A[i] != A[i+1]) ok = 0;
            if(A[i+21] != A[i+22]) ok = 0;
        }
        for (int i = 0; i < 2 && ok; ++i) {
            if(A[i+9] != A[i+10]) ok = 0;
            if(A[i+12] != A[i+13]) ok = 0;
            if(A[i+15] != A[i+16]) ok = 0;
            if(A[i+18] != A[i+19]) ok = 0;
        }
        if(ok){
            ans = min(ans, dep);
            return;
        }
        for (auto &&S : shifts) {
            auto B = A;
            for (int i = 0; i < 5; ++i) {
                swap(B[S[i]], B[S[i+5]]);
            }
            f(dep+1, B, f);
        }
    };
    dfs(0, X, dfs);
    cout << ans << "\n";
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
    return 0;
}