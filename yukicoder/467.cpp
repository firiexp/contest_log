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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int x, y;
    cin >> x >> y;
    int dist = max(abs(x), abs(y)), dmax = *max_element(v.begin(),v.end());
    if(dist == 0) puts("0");
    else if(count(v.begin(),v.end(), dist)) puts("1");
    else cout << max(2, (dist+dmax-1)/dmax) << "\n";
    return 0;
}