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
    int q;
    while(cin >> q, ~q){
        double x = q/2.0;
        while(abs(x*x*x-q) >= 0.00001*q){
            x = x-(x*x*x-q)/(3*x*x);
        }
        printf("%.10lf\n", x);
    }
    return 0;
}