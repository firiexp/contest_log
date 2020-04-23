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
    int q;
    cin >> q;
    vector<array<int, 3>> query(q);
    for (int i = 0; i < q; ++i) {
        int l;
        scanf("%d", &l);
        if(l == 1){
            int p, x;
            scanf("%d %d", &p, &x);
            query[i] = {l, p-1, x};
        }else {
            int x;
            scanf("%d", &x);
            query[i] = {l, x, 0};
        }
    }
    reverse(query.begin(),query.end());
    vector<int> decided(n), ans(n);
    int k = 0;
    for (int i = 0; i < q; ++i) {
        if(query[i][0] == 1){
            if(!decided[query[i][1]]){
                decided[query[i][1]] = 1;
                ans[query[i][1]] = max(query[i][2], k);
            }
        }else if(query[i][0] == 2){
            k = max(k, query[i][1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if(!decided[i]) ans[i] = max(k, v[i]);
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}