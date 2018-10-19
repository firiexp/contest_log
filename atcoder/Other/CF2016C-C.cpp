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
    ll ans = 1;
    cin >> n;
    vector<int> v1(n), v2(n), v3(n, 0);
    for (auto &&i : v1) scanf("%d", &i);
    for (auto &&i : v2) scanf("%d", &i);
    if(v1[n-1] != v2[0]){
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 1; i < n-1; ++i) {
        if(v1[i] == v1[i-1] && v2[i] == v2[i+1]) (ans *= min(v1[i], v2[i])) %= MOD;
        else if(v1[i] > v1[i-1] && v2[i] == v2[i+1] && v2[i] < v1[i]) ans = 0;
        else if(v1[i] == v1[i-1] && v2[i] > v2[i+1] && v2[i] > v1[i]) ans = 0;
        else if(v1[i] > v1[i-1] && v2[i] > v2[i+1] && v2[i] != v1[i]) ans = 0;
    }
    cout << ans << "\n";
    return 0;
}
