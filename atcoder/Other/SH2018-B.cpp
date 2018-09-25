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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if(i) cout << " ";
        cout << (k < l ? l : (r < k ? r : k));
    }
    cout << "\n";
    return 0;
}
