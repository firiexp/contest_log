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

int main() {
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        ll c = b-a;
        for (ll i = 0; i <= 100000; ++i) {
            if(((i*(i+1)/2)&1) == (c&1) && i*(i+1)/2 >= c){
                printf("%lld\n", i);
                break;
            }
        }
    }
    return 0;
}