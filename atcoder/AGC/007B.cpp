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
    vector<int> v(n), v2(n);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        v[k-1] = i;
    }
    int q = 0;
    for (int i = n-1; i >= 0; --i) {
        q += v[i];
        v2[i] = q;
    }
    int p = 0;
    for (int i = 0; i < n; ++i) {
        p += v[i];
        if(i) printf(" ");
        printf("%d", p);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", v2[i]);
    }
    printf("\n");
    return 0;
}
