#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;
using namespace __gnu_pbds;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
    for (int i = 0; i < n; ++i) {
        s.insert(i);
    }
    int cur = 0, sz = n;
    for (int i = 0; i < m; ++i) {
        int a; scanf("%d", &a);
        if(a&1){
            cur = ((cur-a)%sz+sz)%sz;
            s.erase(s.find_by_order(cur));
        }else {
            cur = (cur+a)%sz;
            s.erase(s.find_by_order(cur));
        }
        sz--;
        cur %= sz;
    }
    for (int i = 0; i < q; ++i) {
        int x; scanf("%d", &x);
        if(s.find(x) != s.end()) puts("1");
        else puts("0");
    }
    return 0;
}