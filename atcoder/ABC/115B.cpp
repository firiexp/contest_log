#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
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
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end(), greater<>());
    v[0]/=2;
    cout << accumulate(v.begin(), v.end(), 0) << "\n";
    return 0;
}
