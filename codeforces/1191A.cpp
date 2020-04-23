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
    int x;
    cin >> x;
    x %= 4;
    if(x == 0) puts("1 A");
    else if(x == 1) puts("0 A");
    else if(x == 2) puts("1 B");
    else puts("2 A");
    return 0;
}