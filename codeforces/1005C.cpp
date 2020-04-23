#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&k : v) scanf("%d", &k);

    int ans = n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) m[v[i]]++;
    for (int i = 0; i < n; ++i) {
        int ok = 0;
        for (int j = 30; j >= 0; --j) {
            if(v[i] >= (1 << j)) break;
            if(m.count((1 << j) - v[i]) && (v[i]*2 != (1 << j) || m[(1 << j) - v[i]] >= 2)){
                ok = 1;
                break;
            }

        }
        ans -= ok;
    }
    cout << ans << "\n";
    return 0;
}