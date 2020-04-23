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
    int n;
    cin >> n;
    vector<set<string>> v(100010);
    for (int i = 0; i < n; ++i) {
        string c; int d;
        cin >> c >> d;
        v[d-1].insert(c);
    }
    int cur = 0;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        while(cur < 100005 && !v[cur].count(s)) cur++;
        if(cur == 100005) {
            puts("No");
            return 0;
        }
        cur++;
    }
    puts("Yes");
    return 0;
}