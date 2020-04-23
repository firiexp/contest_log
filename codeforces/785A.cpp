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
    map<string, int> m{
            {"Tetrahedron", 4},
            {"Cube", 6},
            {"Octahedron", 8},
            {"Dodecahedron", 12},
            {"Icosahedron", 20}
    };
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ans += m[s];
    }
    cout << ans << "\n";
    return 0;
}
