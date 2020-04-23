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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if((a >= x && b >= y) && (a + b >= z)) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}