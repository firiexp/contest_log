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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int w;
        scanf("%d", &w);
        v.emplace_back(w);
    }
    sort(v.begin(), v.end());
    if(v[n-1] < k){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int p = v[0];
    for (int i = 1; i < n; ++i) {
        p = __gcd(p, v[i]);
    }
    if(k % p){
        cout << "IMPOSSIBLE\n";
    }else {
        cout << "POSSIBLE\n";
    }
    return 0;
}
