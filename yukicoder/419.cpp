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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int a, b;
    cin >> a >> b;
    long double p = a, q = b;

    if(a == b){
        cout << setprecision(12) << hypot(p, q);
    }else {
        if(p > q) swap(p, q);
        cout << setprecision(12) << sqrt(q*q-p*p);
    }
    puts("");
    return 0;
}
