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
    int x, y, z;
    cin >> x >> y >> z;
    if(z == 0){
        puts("wwW");
        return 0;
    }
    if(y && z % y == 0 && 2*(z/y)-1 <= 10000){
        cout << string(z/y, 'w') << string(z/y-1, 'C') << "\n";
        return 0;
    }
    if(x && z % x == 0 && 2*(z/x)-1 <= 10000){
        cout << string(z/x, 'c') << string(z/x-1, 'C') << "\n";
        return 0;
    }
    if(x == 0 || y == 0){
        puts("NO");
        return 0;
    }
    for (ll i = -5000; i <= 5000; ++i) {
        ll p = z-x*i;
        if(p%y || abs(p/y)*2+abs(i)*2-1 > 10000) continue;
        p /= y;
        if(i > 0 && p > 0){
            cout << string(i, 'c') << string(p, 'w') << string(i+p-1, 'C');
        }else if(i > 0){
            cout << string(-p, 'w') << string(-p-1, 'C') << "cW" << string (i-1, 'c') << string(i-1, 'C');
        }else {
            cout << string(-i, 'c') << string(-i-1, 'C') << "wW" << string (p-1, 'w') << string(p-1, 'C');
        }
        return 0;
    }
    puts("NO");
    return 0;
}