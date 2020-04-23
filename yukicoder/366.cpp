#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int main() {
    int n, X;
    cin >> n >> X;
    int ans = 0;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 0; i < X; ++i) {
        for (int j = i; j < n; j += X) {
            for (int k = i+X; k < n; k += X) {
                if(v[k] < v[k-X]) {
                    swap(v[k], v[k-X]);
                    ans++;
                }
            }
        }
    }
    for (int i = 0; i < n-1; ++i) {
        if(v[i] > v[i+1]) {
            puts("-1");
            return 0;
        }
    }
    cout << ans << "\n";
    return 0;
}
