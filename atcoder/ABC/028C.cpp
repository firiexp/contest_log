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
    vector<int> v(5), v2;
    for (auto &&i : v) cin >> i;
    do {
        v2.emplace_back(v[0]+v[1]+v[2]);
    }while(next_permutation(v.begin(), v.end()));
    sort(v2.begin(), v2.end(), greater<>());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    cout << v2[2] << "\n";
    return 0;
}
