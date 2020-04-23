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
    vector<int> v(5);
    for (auto &&i : v) {
        cin >> i;
        if(i < 40) i = 40;
    }
    cout << accumulate(v.begin(), v.end(), 0)/5 << "\n";
    return 0;
}
