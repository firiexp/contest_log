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
    int n;
    cin >> n;
    map<pair<int, int>, int> v;
    v[{2, 8}] = 1;
    v[{3, 9}] = 2;
    v[{7, 9}] = 3;
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v[{c, d}] = v[{a, b}];
        v[{a, b}] = 0;
    }
    if(v[{5, 8}] == 1 && v[{4, 8}] == 2 && v[{6, 8}] == 3) puts("YES");
    else puts("NO");
    return 0;
}