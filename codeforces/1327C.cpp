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
    int n, m;
    cin >> n >> m;
    string ans;
    for (int i = 0; i < n-1; ++i) ans += 'U';
    for (int i = 0; i < m-1; ++i) ans += 'L';
    for (int i = 0; i < n; ++i) {
        if(i&1){
            for (int j = 0; j < m-1; ++j) {
                ans += 'L';
            }
        }else {
            for (int j = 0; j < m-1; ++j) {
                ans += 'R';
            }
        }
        if(i != n-1) ans += 'D';
    }
    cout << ans.size() << "\n";
    cout << ans << "\n";
    return 0;
}