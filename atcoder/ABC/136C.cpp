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
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    v[0]--;
    for (int i = 1; i < n; ++i) {
        if(v[i-1] > v[i]){
            puts("No");
            return 0;
        }else if(v[i-1] < v[i]) v[i]--;
    }
    puts("Yes");
    return 0;
}