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
    int n;
    cin >> n;
    vector<int> v, v2;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        v.emplace_back(k); v2.emplace_back(k);
    }
    sort(v.begin(), v.end());

    if(v[n/2] != v[n/2-1]) for (auto &&x : v2) {
        if(lower_bound(v.begin(), v.end(), x)-v.begin() < n/2){
            cout << v[n/2] << "\n";
        }else {
            cout << v[n/2-1] << "\n";
        }
    }
    else for (int i = 0; i < n; ++i) cout << v[n/2] << "\n";
    return 0;
}
