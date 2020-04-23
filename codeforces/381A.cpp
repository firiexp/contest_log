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
    deque<int> Q;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        Q.emplace_back(x);
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i) {
        if(Q.front() < Q.back()) (i%2 ? ans2 : ans1) += Q.back(), Q.pop_back();
        else (i%2 ? ans2 : ans1) += Q.front(), Q.pop_front();
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}