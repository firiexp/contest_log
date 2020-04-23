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
    vector<int> v(2, 0);
    for (int i = 0; i < n; ++i) {
        ll k;
        scanf("%lld", &k);
        v[(k+MOD-1)%2]++;
    }
    cout << (*max_element(v.begin(), v.end())) - (*min_element(v.begin(), v.end())) << "\n";
    return 0;
}
