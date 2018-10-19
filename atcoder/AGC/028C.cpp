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
    ll ans = 0;
    cin >> n;
    vector<int> v1(n);
    vector<int> v2(n);
    vector<int> used(n, 0);
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v1[i], &v2[i]);
        if(!m[v1[i]]) m[v1[i]] = v2[i];
        else m[v1[i]] = INF<int>;
    }
    sort(v1.begin(), v1.end());
    sort(v2.rbegin(), v2.rend());
    for (int i = 0; i < n; ++i) {
        if(m[v1[i]] != v2[i]){
            if(used[i]) ans += min(v1[i], v2[i-1]);
            else ans += min(v1[i], v2[i]);
            used[i] = 1;
        }else {
            used[i+1] = 1;
        }
    }
    return 0;
}
