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

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = 0;
    for (int i = 0; i <= k && i <= n; ++i) {
        for (int j = 0; i+j <= k && i+j <= n; ++j) {
            GPQ<int> q;
            int s = 0;
            int sousa = k-i-j;
            for (int l = 0; l < i; ++l) {
                q.emplace(v[l]);
                s += v[l];
            }
            for (int l = 0; l < j; ++l) {
                q.emplace(v[n-l-1]);
                s += v[n-l-1];
            }
            while(sousa && !q.empty() && q.top() < 0){
                sousa--;
                s -= q.top();
                q.pop();
            }
            ans = max(ans, s);
        }
    }
    cout << ans << "\n";
    return 0;
}