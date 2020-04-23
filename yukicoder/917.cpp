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
    map<int, ll> m;
    for (int i = 0; i < n; ++i) {
        map<int, ll> m2;
        m2[v[i]]++;
        for (auto &&j : m) {
            m2[__gcd(j.first, v[i])] += j.second;
            m2[j.first] += j.second;
        }
        m = m2;
    }
    cout << m[1] << "\n";
    return 0;
}