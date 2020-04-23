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
    ll u, v;
    cin >> u >> v;
    if(u > v || u%2 != v%2){
        puts("-1");
    }else if(u == 0 && v == 0){
        puts("0");
    }else if(u == v){
        printf("%d\n", 1);
        printf("%lld\n", u);
    }else if((v-u)%2 == 0){
        if((((v-u)/2)&u) == 0){
            cout << 2 << "\n";
            cout << (v-u)/2 << " " << (v-u)/2+u << "\n";
        }else {
            cout << 3 << "\n";
            cout << u << " " << (v-u)/2 << " " << (v-u)/2 << "\n";
        }
    }else {
        cout << 3 << "\n";
        cout << u-1 << " " << (v-u)/2 << " " << (v-u)/2 << "\n";
    }

    return 0;
}