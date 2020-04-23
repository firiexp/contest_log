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
    double a, b;
    while(cin >> a >> b) {
        if(a < 35.5 && b < 71) puts("AAA");
        else if(a < 37.5 && b < 77) puts("AA");
        else if(a < 40 && b < 83) puts("A");
        else if(a < 43 && b < 89) puts("B");
        else if(a < 50 && b < 105) puts("C");
        else if(a < 55 && b < 116) puts("D");
        else if(a < 70 && b < 148) puts("E");
        else puts("NA");
    }
    return 0;
}