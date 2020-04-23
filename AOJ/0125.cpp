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
    int a, b, c, d, e, f;
    auto get = [&](int y, int m, int d){
        if(m <= 2) y--, m += 12;
        return 365*y+y/4-y/100+y/400+306*(m+1)/10+d-428;
    };
    while(cin >> a >> b >> c >> d >> e >> f, ~a){
        cout << get(d, e, f) - get(a, b, c) << "\n";
    }
    return 0;
}