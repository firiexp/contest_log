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
    vector<int> v(n);
    map<int, int> m;
    for (auto &&i : v) {
        scanf("%d", &i);
        m[i]++;
    }
    sort(v.begin(), v.end(), greater<>());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(!m[v[i]]) continue;
        m[v[i]]--;
        int k = 1;
        while (k <= v[i]) k <<= 1;
        int y = k-v[i];
        if(m[y]) {
            ans++;
            m[y]--;
        }
    }
    cout << ans << "\n";
    return 0;
}
