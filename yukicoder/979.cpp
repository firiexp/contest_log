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

static constexpr int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    int M = 300001;
    vector<vector<int>> B(M);
    vector<int> v(n);
    for (auto &&k : v) scanf("%d", &k);
    vector<int> dp(n, 1), dp2(M, 0);
    for (int i = 1; i < M; ++i) {
        for (int j = 2*i; j < M; j += i) {
            B[j].emplace_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        dp2[v[i]] = max(dp2[v[i]], 1);
        for (auto &&j : B[v[i]]) {
            dp2[v[i]] = max(dp2[v[i]], dp2[j]+1);
        }
    }
    cout << *max_element(dp2.begin(),dp2.end()) << "\n";
    return 0;
}