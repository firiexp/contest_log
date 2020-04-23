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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    queue<int> Q;
    for (int i = 0; i < k-1; ++i) {
        if(v[i] < v[i+1]) Q.emplace(i);
    }
    int ans = (Q.size() != k-1)+1;
    for (int i = 0; i < n-k; ++i) {
        int ok = 0;
        if(!Q.empty() && Q.front() == i) Q.pop(), ok++;
        if(v[i+k-1] < v[i+k]) Q.emplace(i), ok++;
        ans += (ok != 0 && !Q.size() != k-1);
    }
    cout << ans << "\n";
    return 0;
}