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
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1, 0);
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        v[l-1]++; v[r]--;
    }
    cout << v[0]%2;
    for (int i = 1; i < n; ++i) {
        v[i] = (v[i]+v[i-1]+400000)%2;
        printf("%d", v[i]);
    }
    cout << "\n";
    return 0;
}
