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
    int n; string s;
    cin >> n >> s;
    array<int, 256> v{};
    for (auto &&i : s) v[i]++;
    cout << v['a']+v['i']+v['u']+v['e']+v['o'] << "\n";
    return 0;
}