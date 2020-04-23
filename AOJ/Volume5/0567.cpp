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
    int p = a, q = c;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        if(p*v[i] >= q*b) p += b, q += v[i];
        else break;
    }
    cout << q/p << "\n";
    return 0;
}
