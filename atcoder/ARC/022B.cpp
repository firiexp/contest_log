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
    vector<int> v(n);
    array<int, 100001> u{};
    for (auto &&i : v) scanf("%d", &i);
    int l = 0, r = 0, ans = 0;
    while(r != n){
        u[v[r]]++;
        while(u[v[r]] > 1) u[v[l++]]--;
        r++;
        ans = max(ans, r-l);
    }
    cout << ans << "\n";
    return 0;
}
