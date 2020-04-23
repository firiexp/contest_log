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
    vector<int> u(n-1), v(n-1);
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n-1; ++i) {
        scanf("%d %d", &u[i], &v[i]);
        a += u[i]; b += v[i];
        c = max(c, u[i]+v[i]);
    }
    cout << a+b-max({a, b, c})+1 << "\n";
    return 0;
}