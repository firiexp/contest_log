#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, INF<int>), c(n);
    v[0] = 0;
    for (auto &&i : c) scanf("%d", &i);
    for (int i = 0; i < n-1; ++i) {
        if(i+1 < n) v[i+1] = min(v[i+1],v[i]+abs(c[i+1]-c[i]));
        if(i+2 < n) v[i+2] = min(v[i+2],v[i]+abs(c[i+2]-c[i]));
    }
    cout << v[n-1] << "\n";
    return 0;
}
