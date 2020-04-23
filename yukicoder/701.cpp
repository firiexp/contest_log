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
    string s = "aaaaaa";
    for (int i = 0; i < n-1; ++i) {
        s[4]++;
        for (int j = 4; j >= 1; --j) {
            if('z' < s[j]) s[j] = 'a', s[j-1]++;
        }
        cout << s << "\n";
    }
    cout << s.substr(0, 5) << 'n' << "\n";
    return 0;
}
