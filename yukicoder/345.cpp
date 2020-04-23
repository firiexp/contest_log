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
    string s;
    cin >> s;
    int n = s.length();
    int p = 101;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                if(s[i] == 'c' && s[j] == 'w' && s[k] == 'w'){
                    p = min(p, k-i+1);
                }
            }
        }
    }
    cout << (p == 101 ? -1 : p) << "\n";
    return 0;
}
