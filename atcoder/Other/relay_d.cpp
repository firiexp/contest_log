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
    int a, b, c;
    cin >> a >> b >> c;
    printf("%d %d %d\n", a, b, 3*c-a-b);
    printf("%d %d %d\n", -2*a-b+4*c, c, 2*a+b-2*c);
    printf("%d %d %d\n", a+b-c, 2*c-b, 2*c-a);
    return 0;
}