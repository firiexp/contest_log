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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, r;
    while(cin >> n >> r, n | r){
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = n-i;
        }
        for (int i = 0; i < r; ++i) {
            int p, c;
            cin >> p >> c;
            vector<int> u(c+p-1);
            for (int j = 0; j < c+p-1; ++j) {
                u[(j+c)%(c+p-1)] = v[j];
            }
            for (int j = 0; j < c+p-1; ++j) {
                v[j] = u[j];
            }
        }
        cout << v.front() << "\n";
    }
    return 0;
}
