#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    int p = 0, q = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        int a, b;
        cin >> s;
        scanf("%d %d", &a, &b);
        if(a > b) swap(a, b);
        if(s == "+"){
            p = max(p, a);
            q = max(q, b);
        }else {
            puts((p <= a && q <= b) ? "YES" : "NO");
        }
    }
    return 0;
}
