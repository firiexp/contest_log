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
    vector<int> w(10), k(10);
    for (auto &&i : w) scanf("%d", &i);
    for (auto &&i : k) scanf("%d", &i);
    sort(w.begin(), w.end(), greater<>());
    sort(k.begin(), k.end(), greater<>());
    cout << accumulate(w.begin(), w.begin()+3, 0) << " " <<
            accumulate(k.begin(), k.begin()+3, 0) << "\n";
    return 0;
}
