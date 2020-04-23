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
    vector<pair<int, int>> black{{1, 0}, {2, 0}};
    int n, m;
    cin >> n >> m;
    if(count(black.begin(),black.end(), pair<int, int>{n, m})) puts("Impossible");
    else puts("Possible");
    return 0;
}