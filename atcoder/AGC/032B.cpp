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
    int n;
    cin >> n;
    int m = n/2;
    vector<vector<int>> v(n, vector<int> (n, 1));
    for (int i = 0; i < m; ++i) {
        v[i][m*2-i-1] = v[m*2-i-1][i] = 0;
    }
    cout << n*(n-1)/2 - m << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(v[i][j]) cout << i+1 << " " << j+1 << "\n";
        }
    }
    return 0;
}
