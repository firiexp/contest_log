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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    sort(v.begin(), v.end());
    partial_sum(v.begin(), v.end(), v.begin());
    cout << v[k-1]+(ll)k*(k-1)/2 << "\n";
    return 0;
}
