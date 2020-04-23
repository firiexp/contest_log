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
    int n;
    cin >> n;
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &xs[i], &ys[i]);
    }
    ll a, b, c, d, e, f;
    cout << "? 0 0" << endl;
    cin >> c >> f;
    cout << "? 1 0" << endl;
    cin >> a >> d;
    a -= c; d -= f;
    cout << "? 0 1" << endl;
    cin >> b >> e;
    b -= c; e -= f;
    cout << "!" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a*xs[i]+b*ys[i]+c << " " << d*xs[i]+e*ys[i]+f << endl;
    }
    return 0;
}