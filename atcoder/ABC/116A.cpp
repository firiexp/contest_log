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
    vector<int> v(3);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end());
    cout << v[0]*v[1]/2 << "\n";
    return 0;
}
