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
    priority_queue<int> Q;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sum += x;
        Q.emplace(x);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        while(Q.top() >= x){
            int y = Q.top(); Q.pop();
            sum -= y-y%x;
            Q.emplace(y%x);
        }
        printf("%lld\n", sum);
    }
    return 0;
}