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
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    int ok = 1;
    while(x){
        if(!a) {
            puts("NO");
            return 0;
        }
        a--; x--;
    }
    while(y){
        if(!a && !b) {
            puts("NO");
            return 0;
        }
        if(a) a--, y--;
        else b--, y--;
    }
    while(z){
        if(!a && !b && !c) {
            puts("NO");
            return 0;
        }
        if(a) a--, z--;
        else if(b) b--, z--;
        else c--, z--;
    }
    puts("YES");
    return 0;
}