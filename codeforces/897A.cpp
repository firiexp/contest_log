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
    int n, m; string s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int a, b; char p, q;
        scanf("%d %d %c %c", &a, &b, &p, &q);
        for (int j = a-1; j < b; ++j) {
            if(s[j] == p) s[j] = q;
        }
    }
    cout << s << "\n";

    return 0;
}
