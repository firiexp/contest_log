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
    int n, m;
    while(cin >> n >> m, n){
        vector<int> v(m);
        for (int i = 0; i < n; ++i) {
            int d, x;
            cin >> d >> x;
            v[d-1] = max(v[d-1], x);
        }
        cout << accumulate(v.begin(),v.end(), 0) << "\n";
    }
    return 0;
}