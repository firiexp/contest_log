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
    vector<int> v(101);
    for (int i = 1; i <= n; ++i) {
        int k = i;
        for (int j = 2; j <= 100; ++j) {
            while(k%j == 0) {
                v[j]++;
                k /= j;
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= 100; ++i) {
        if(v[i] >= 74) ans++;
        for (int j = i+1; j <= 100; ++j) {
            if(v[i] >= 24 && v[j] >= 2) ans++;
            if(v[i] >= 2 && v[j] >= 24) ans++;
            if(v[i] >= 14 && v[j] >= 4) ans++;
            if(v[i] >= 4 && v[j] >= 14) ans++;
            for (int k = j+1; k <= 100; ++k) {
                if(v[i] >= 2 && v[j] >= 4 && v[k] >= 4) ans++;
                if(v[i] >= 4 && v[j] >= 2 && v[k] >= 4) ans++;
                if(v[i] >= 4 && v[j] >= 4 && v[k] >= 2) ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
