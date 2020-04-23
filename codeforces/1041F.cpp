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
    int n, tmp, m;
    cin >> n >> tmp;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    cin >> m >> tmp;
    vector<int> u(m);
    for (auto &&j : u) scanf("%d", &j);
    int ans = 2;
    for (int k = 2; k <= MOD; k *= 2) {
        map<ll, int> A;
        for (auto &&i : v) A[i&(k-1)]++;
        for (auto &&i : u) A[(i+k/2)&(k-1)]++;
        for (auto &&i : A) ans = max(ans, i.second);
    }
    cout << ans << "\n";
    return 0;
}