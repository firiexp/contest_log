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
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b; ++i) {
        int k, l;
        cin >> k >> l;
        if(a == k) a = l;
        else if(a == l) a = k;
    }
    cout << a << "\n";
    return 0;
}
