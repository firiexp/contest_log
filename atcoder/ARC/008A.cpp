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
    vector<int> v(51, INF<int>);
    v[0] = 0;
    for (int i = 1; i <= 50; ++i) {
        if(i > 9) v[i] = min(v[i], v[i-10]+100);
        v[i] = min(v[i], v[i-1]+15);
    }
    for (int i = 49; i >= 0; --i) {
        v[i] = min(v[i+1], v[i]);
    }
    cout << v[n] << "\n";
    return 0;
}
