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
    int n, k;
    cin >> n >> k;
    vector<int> v(n), cnt(k);
    for (auto &&i : v) scanf("%d", &i), cnt[i-1]++;
    int a = 0, b = 0;
    for (int i = 0; i < k; ++i) {
        a += cnt[i]/2;
        b += cnt[i]%2;
    }
    int ans = 0;
    for (int i = 0; i < (n+1)/2; ++i) {
        if(a) a--, ans += 2;
        else b--, ans++;
    }
    cout << ans << "\n";
    return 0;
}