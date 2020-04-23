#include <iostream>
#include <algorithm>
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
    int n;
    while(cin >> n, n){
        vector<int> a(n), b(n-1);
        for (auto &&i : a) scanf("%d", &i);
        for (auto &&j : b) scanf("%d", &j);
        sort(b.begin(),b.end(), greater<>());
        ll S = accumulate(a.begin(),a.end(), 0LL), ans = S*n;
        for (int i = 0; i < n-1; ++i) {
            S += b[i];
            ans = max(ans, (n-i-1)*S);
        }
        cout << ans << "\n";
    }
    return 0;
}