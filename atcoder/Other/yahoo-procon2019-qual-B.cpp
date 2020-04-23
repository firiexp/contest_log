#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    using P = pair<int, int>;
    vector<vector<int>> v(4, vector<int>(4, 0));
    for (int i = 0; i < 3; ++i) {
        int a, b;
        cin >> a >> b;
        v[a-1][b-1] = v[b-1][a-1] = 1;
    }
    vector<int> s = {0, 1, 2, 3};
    do {
        int x = 1;
        for (int i = 0; i < 3; ++i) {
            x &= v[s[i]][s[i+1]];
        }
        if(x) {
            puts("YES");
            return 0;
        }
    }while(next_permutation(s.begin(), s.end()));
    puts("NO");
    return 0;
}
