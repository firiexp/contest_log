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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    a = n-a, b = n-b, c = n-c;
    if(!(a*b*c)) {
        cout << "NO" << "\n";
        return 0;
    }
    vector<int> v(400, INF<int>);
    v[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if(i == a || i == b || i == c) continue;
        v[i]=min(v[i], v[i-1]+1);
        if(i>1) v[i] = min(v[i], v[i-2]+1);
        if(i>2) v[i] = min(v[i], v[i-3]+1);
    }
    cout << (v[n] <= 100 ? "YES\n": "NO\n");
    return 0;
}
