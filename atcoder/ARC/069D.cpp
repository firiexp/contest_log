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
    string s;
    cin >> n >> s;
    s += s[0];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            vector<bool> v(n+2);
            v[0] = i, v[1] = j;
            for (int k = 1; k <= n; ++k) {
                v[k+1] = (v[k-1] != v[k]);
                if(s[k] == 'x') v[k+1] = !v[k+1];
            }
            if(v[0] == v[n] && v[1] == v[n+1]){
                for (int k = 0; k < n; ++k) {
                    printf("%c", (v[k] ? 'W' : 'S'));
                }
                printf("\n");
                return 0;
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}
