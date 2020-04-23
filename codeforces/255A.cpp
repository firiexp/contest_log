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
    vector<int> v(n), u(3);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 0; i < n; ++i) {
        u[i%3] += v[i];
    }
    cout << (vector<string>{"chest", "biceps", "back"}[max_element(u.begin(),u.end())-u.begin()]) << "\n";
    return 0;
}