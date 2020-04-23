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

template <class T>
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};

int main() {
    int n, m, a, b, c, t;
    while(cin >> n >> m >> a >> b >> c >> t, n){
        vector<int> v(n);
        for (auto &&l : v) scanf("%d", &l);
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(i == j+1) mat[i][j] = a;
                if(i == j) mat[i][j] = b;
                if(i == j-1) mat[i][j] = c;
            }
        }
        vector<vector<int>> ret(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            ret[i][i] = 1;
        }
        while(t > 0){
            if(t&1) {
                vector<vector<int>> J(n, vector<int>(n, 0));
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        for (int k = 0; k < n; ++k) {
                            (J[i][j] += mat[i][k]*ret[k][j]) %= m;
                        }
                    }
                }
                ret = J;
            }
            vector<vector<int>> J(n, vector<int>(n, 0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        (J[i][j] += mat[i][k]*mat[k][j]) %= m;
                    }
                }
            }
            mat = J;
            t >>= 1;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                (ans[i] += ret[i][j]*v[j]) %= m;
            }
        }
        for (int i = 0; i < n; ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}