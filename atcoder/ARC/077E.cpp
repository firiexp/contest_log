#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &&i : v) {
        scanf("%d", &i);
        i--;
    }
    ll X = 0;
    vector<ll> ans1(2*m+1), ans2(2*m+1);
    for (int i = 0; i < n-1; ++i) {
        int a = v[i], b = v[i+1];
        if(b < a) b += m;
        ans1[a+2] += 1;  ans1[b+1] -= 1; ans2[b+1] -= b-a-1;
        X += b-a;
    }
    for (int i = 0; i < 2*m; ++i) {
        ans1[i+1] += ans1[i];
    }
    for (int i = 0; i < 2*m; ++i) {
        ans1[i+1] += ans1[i] + ans2[i+1];
    }
    for (int i = 0; i < m; ++i) {
        ans1[i] += ans1[i+m];
    }
    cout << X - *max_element(ans1.begin(), ans1.end()) << "\n";
    return 0;
}
