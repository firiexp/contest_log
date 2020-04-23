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
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int ans = 0;
    array<int, 5> dy{-1, 1, -1, 1, 0}, dx{1, 1, -1, -1, 0};
    for (int i = 1; i+1 < n; ++i) {
        for (int j = 1; j+1 < n; ++j) {
            int ok = 1;
            for (int k = 0; k < 5; ++k) {
                if(v[i+dy[k]][j+dx[k]] == '.'){
                    ok = 0;
                }
            }
            ans += ok;
        }
    }
    cout << ans << "\n";
    return 0;
}