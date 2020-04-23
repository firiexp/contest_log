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
    int n, r=0, b=0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if(s[j] == 'R') r++;
            else if(s[j] == 'B') b++;
        }
    }
    if(r > b) cout << "TAKAHASHI\n";
    else if(r < b) cout << "AOKI\n";
    else cout << "DRAW\n";
    return 0;
}
