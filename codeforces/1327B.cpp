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
    int n;
    scanf("%d", &n);
    vector<int> ok(n);
    vector<int> bad(n);
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        v[i].reserve(k);
        int married = 0;
        for (int j = 0; j < k; ++j) {
            int x;
            scanf("%d", &x); x--;
            v[i].emplace_back(x);
            if(!married && !ok[x]){
                married = 1;
                ok[x] = 1;
            }
        }
        if(!married) bad[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if(bad[i]){
            for (int j = 0; j < n; ++j) {
                if(!ok[j]){
                    puts("IMPROVE");
                    printf("%d %d\n", i+1, j+1);
                    return;
                }
            }
        }
    }
    puts("OPTIMAL");
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}