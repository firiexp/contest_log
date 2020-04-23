#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n*(n-1)/2; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(c > d) swap(a, b);
        if(c == d) v[a-1]++, v[b-1]++;
        else v[b-1] += 3;
    }
    vector<int> v2 = v;
    sort(v2.begin(), v2.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        cout << lower_bound(v2.begin(), v2.end(), v[i], greater<>()) - v2.begin() + 1 << "\n";
    }
    return 0;
}
