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
    int n, m;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    v.emplace_back(2020);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x; x--;
        if(v[x]+1 < v[x+1]) v[x]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << v[i] << "\n";
    }
    return 0;
}
