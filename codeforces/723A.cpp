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
    vector<int> v(3);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    cout << v[2] - v[0] << "\n";
    return 0;
}