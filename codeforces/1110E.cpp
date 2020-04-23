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
    vector<int> v(n), v2(n);
    for (auto &&i : v) scanf("%d", &i);
    for (auto &&i : v2) scanf("%d", &i);
    if(v[0] != v2[0] || v[n-1] != v2[n-1]) {
        puts("No");
        return 0;
    }

    return 0;
}
