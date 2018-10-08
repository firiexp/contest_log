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
    int n, m;
    cin >> n >> m;
    vector<int> v(m), checked(n, 0);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        v[m-i-1] = k-1;
    }
    for (int i = 0; i < m; ++i) {
        if(!checked[v[i]]){
            printf("%d\n", v[i]+1);
            checked[v[i]] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(!checked[i]) printf("%d\n", i+1);
    }
    return 0;
}
