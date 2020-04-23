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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int dx = abs(c-a), dy = abs(d-b);
    if(dx == 0 || dy == 0){
        cout << 0 << "\n";
    }else {
        int g = __gcd(dx, dy);
        cout << (dx/g+dy/g-1)*g << "\n";
    }
    return 0;
}