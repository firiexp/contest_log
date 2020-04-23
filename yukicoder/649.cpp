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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int q, k;
    cin >> q >> k;
    priority_queue<ll> Q;
    GPQ<ll> Q2;
    while(q--){
        int t;
        scanf("%d", &t);
        if(t == 1){
            ll v;
            scanf("%lld", &v);
            Q.emplace(v);
            if(Q.size() > k) Q2.emplace(Q.top()), Q.pop();
        }else {
            if(Q.size() >= k) {
                printf("%lld\n", Q.top());
                Q.pop();
                if(!Q2.empty()) {
                    Q.emplace(Q2.top()); Q2.pop();
                }
            }
            else puts("-1");
        }
    }
    return 0;
}