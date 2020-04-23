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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> A(a), B(b);

    for (auto &&i : A) scanf("%d", &i);
    for (auto &&j : B) scanf("%d", &j);
    int ans = *min_element(A.begin(),A.end()) + *min_element(B.begin(),B.end());
    for (int i = 0; i < m; ++i) {
        int x, y, c; scanf("%d %d %d", &x, &y, &c);
        ans = min(ans, A[x-1]+B[y-1]-c);
    }
    cout << ans << "\n";
    return 0;
}