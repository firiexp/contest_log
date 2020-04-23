#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].second, &v[i].first);
    }
    ll s = 0;
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i) {
        s += v[i].second;
        if(s > v[i].first){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}