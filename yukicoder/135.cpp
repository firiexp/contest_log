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
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int ans = INF<int>;
    if(v.size() == 1){
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 0; i < v.size()-1; ++i) {
        ans = min(ans, v[i+1]-v[i]);
    }
    cout << ans << "\n";
    return 0;
}
