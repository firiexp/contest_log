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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    vector<int> v(4);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    int ans = INF<int>;
    do {
        ans = min(ans, abs(v[0]+v[1]-v[2]-v[3]));
    }while(next_permutation(v.begin(),v.end()));
    cout << ans << "\n";
    return 0;
}