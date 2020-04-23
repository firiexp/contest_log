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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.rbegin(), v.rend());
    partial_sum(v.begin(), v.end(), v.begin());
    for (int i = 0; i < n; ++i) {
        if(v[i] >= k){
            cout << i+1 << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
