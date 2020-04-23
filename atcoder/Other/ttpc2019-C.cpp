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
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    ll a = x;
    for (auto &&i : v) {
        scanf("%lld", &i);
        if(i != -1) a ^= i;
    }

    int found = (a == 0);
    for (int i = 0; i < n; ++i) {
        if(v[i] == -1){
            if(!found){
                ll p = 0;
                for (int j = 31; j >= 0; --j) {
                    if((a & (1LL << j)) && (p + (1LL << j)) <= x){
                        p ^= (1LL << j);
                        a ^= (1LL << j);
                    }
                }
                v[i] = p;
                found |= (a == 0);
            }else {
                v[i] = 0;
            }
        }
    }
    if(!found){
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%lld", v[i]);
    }
    puts("");
    return 0;
}