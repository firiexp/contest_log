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
    vector<int> v, v2{0};
    v.emplace_back(0);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        v.emplace_back(k);
    }
    v.emplace_back(0);
    int sum = 0;
    for (int i = 0; i < n+1; ++i) {
        sum += abs(v[i+1]-v[i]);
        v2.emplace_back(sum);
    }
    for (int i = 1; i <= n; ++i) {
        cout << v2[i-1] + v2[n+1]-v2[i+1] + abs(v[i+1]-v[i-1]) << "\n";
    }
    return 0;
}
