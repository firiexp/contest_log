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
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a = min(a, n-a+1);
        b = min(b, n-b+1);
        int x = ((n+1)/2-max((n+1)/2-a, (n+1)/2-b)-1)%3+1;
        cout << x << "\n";
    }
    return 0;
}
