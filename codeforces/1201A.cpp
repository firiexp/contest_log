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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> A(m);
    for (auto &&j : A) scanf("%d", &j);
    array<int, 256> cnt{};
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        fill(cnt.begin(),cnt.end(), 0);
        for (int j = 0; j < n; ++j) {
            cnt[v[j][i]]++;
        }
        ans += *max_element(cnt.begin(),cnt.end())*A[i];
    }
    cout << ans << "\n";
    return 0;
}