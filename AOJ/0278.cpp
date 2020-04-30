#include <iostream>
#include <algorithm>
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
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, b, p;
        cin >> x >> y >> b >> p;
        cout << min(x*b+y*p, (max(b, 5)*x+max(p, 2)*y)/5*4) << "\n";
    }
    return 0;
}