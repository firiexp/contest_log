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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    priority_queue<int> Q;
    int a = n-1, ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        Q.push(v[i]);
        if(a == i) {
            ans++;
            a -= Q.top(); Q.pop();
        }
    }
    cout << ans << "\n";
    return 0;

}