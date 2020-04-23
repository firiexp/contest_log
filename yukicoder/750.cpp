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
    vector<pair<int, int>> v(n);
    for (auto &&i : v) {
        scanf("%d %d", &i.first, &i.second);
    }
    sort(v.begin(), v.end(), [](pair<int, int> p1, pair<int, int> p2){return p1.first * p2.second > p1.second*p2.first;});
    for (auto &&i : v) {
        printf("%d %d\n", i.first, i.second);
    }
    return 0;
}
