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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<typename T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    Tree<pair<ll, int>> S;
    for (int i = 0; i < n; ++i) {
        S.insert({0, i});
    }
    while(q--){
        int t;
        scanf("%d", &t);
        if(t == 0){
            int a, b;
            scanf("%d %d", &a, &b); a--;
            S.erase(S.find({v[a], a}));
            v[a] -= b;
            S.insert({v[a], a});
        }else {
            int a;
            scanf("%d", &a); a--;
            auto res = S.find_by_order(a);
            printf("%d %lld\n", res->second+1, -res->first);
        }
    }
    return 0;
}