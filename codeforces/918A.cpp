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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;



int main() {
    vector<int> v(16);
    v[0] = 1, v[1] = 1;
    string ans(1010, 'o');
    ans[0] = 'O';
    for (int i = 0; i < 14; ++i) {
        v[i+2] = v[i+1] + v[i];
        ans[v[i+2]-1] = 'O';
    }
    int n;
    cin >> n;
    cout << ans.substr(0, n) << "\n";
    return 0;
}