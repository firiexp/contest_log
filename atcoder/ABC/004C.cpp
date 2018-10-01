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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n;
    cin >> n;
    n = n % 30;
    vector<int> v{1, 2, 3, 4, 5, 6};
    for (int i = 0; i < n; ++i) {
        swap(v[i%5], v[i%5+1]);
    }
    for (auto &&a : v) {
        cout << a;
    }
    cout << "\n";
    return 0;
}
