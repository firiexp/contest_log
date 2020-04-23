#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, int>> v;
    for (int i = 0; i < k; ++i) {
        int a;
        scanf("%d", &a);
        v.emplace(a, i+1);
    }
    cout << v.top().second << "\n";
    for (int i = 0; i < n-k; ++i) {
        int a;
        scanf("%d", &a);
        v.emplace(a, i+1+k);
        v.pop();
        cout << v.top().second << "\n";
    }
    return 0;
}
