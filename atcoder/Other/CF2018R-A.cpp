#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<string> v {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"
    };
    map<string, int> m;
    for (int i = 0; i < 7; ++i) {
        m[v[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cout << v[(m[s]+1)%7] << "\n";
    }
    return 0;
}
