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
    vector<int> v(4);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[(a%2)*2+(b%2)]++;
    }
    int ans = v[0]/2 + v[1]/2 + v[2]/2 + v[3]/2;
    cout << (ans%2 == 0 ? "Bob" : "Alice");
    return 0;
}
