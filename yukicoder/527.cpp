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
    array<int, 100001> a{};
    for (int i = 0; i < n; ++i) {
        int v, w; cin >> v >> w;
        for (int j = 100000; j >= w; --j) {
            a[j] = max(a[j], a[j-w]+v);
        }
    }
    int V; cin >> V;
    cout << max(1, static_cast<int>(lower_bound(a.begin(),a.end(), V) - a.begin())) << "\n";
    if(a.back() == V) puts("inf");
    else cout << upper_bound(a.begin(),a.end(), V) - a.begin()-1 << "\n";
    return 0;
}