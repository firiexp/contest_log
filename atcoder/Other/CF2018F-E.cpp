#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <functional>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    deque<int> Q;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        while(!Q.empty() && v[Q.back()] >= v[i]) Q.pop_back();
        Q.push_back(i);
        if (i - k +1 >= 0) {
            if(Q.front() == i-k) Q.pop_front();
        }
        ans += v[Q.front()];
    }
    cout << ans << "\n";
    return 0;
}
