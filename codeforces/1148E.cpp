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
    vector<int> v(n), u(n);
    ll s = 0;
    for (auto &&i : v) scanf("%d", &i), s += i;
    for (auto &&j : u) scanf("%d", &j), s -= j;
    if(s != 0){
        puts("NO");
        return 0;
    }

    return 0;
}