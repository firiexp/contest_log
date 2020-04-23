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
    vector<int> v(6);
    for (auto &&i : v) cin >> i;
    sort(v.begin(), v.end());
    printf("%.2f", 0.25*(v[1]+v[2]+v[3]+v[4]));
    return 0;
}
