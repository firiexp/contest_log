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
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < m; ++i) {
        int s = 0;
        map<int, int> M;
        M[0]++;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            v[j] += x;
            s += v[j];
            if(M.count(s-777)) {
                puts("YES");
                return 0;
            }
            M[s]++;
        }
    }
    puts("NO");
    return 0;
}
