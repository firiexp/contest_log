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
    string s;
    cin >> s;
    vector<string> v = {"0", "1", "01", "10", "010", "101"};
    for (int i = 0; i < 6; ++i) {
        if(v[i] == s) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
