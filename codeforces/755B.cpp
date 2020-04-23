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
    int n, m, a = 0, b = 0;
    cin >> n >> m;
    map<string, int> mp1, mp2;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if(!mp1[s]) a++;
        mp1[s]++;
    }
    int k = 0;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if(!mp2[s]) b++;
        if(mp1[s]) k++;
        mp2[s]++;
    }
    a += k % 2;
    puts(a > b ? "YES" : "NO");
    return 0;
}
