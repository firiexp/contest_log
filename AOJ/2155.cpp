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
    while(cin >> n >> m, n|m){
        vector<int> v(n);
        v[0] = 1;
        vector<array<int, 3>> p(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < 3; ++j) {
                scanf("%d", &p[i][j]);
            }
        }
        sort(p.begin(),p.end());
        for (int i = 0; i < m; ++i) {
            v[p[i][2]-1] |= v[p[i][1]-1];
        }
        cout << count(v.begin(),v.end(), 1) << "\n";
    }
    return 0;
}