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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (auto &&i : v) scanf("%d", &i);
    for (int j = n; j >= 3; --j) {
        v[j-2] += v[j]; v[j] = 0;
    }
    int cur = n;
    while(cur != 0 && v[cur] == 0) cur--;
    cout << cur << "\n";
    for (int i = 0; i <= cur; ++i) {
        if(i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
    return 0;
}
