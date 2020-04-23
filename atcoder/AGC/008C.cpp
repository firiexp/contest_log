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
    ll i, o, j, l;
    cin >> i >> o >> j >> j >> l;
    cout << o+max((i/2+j/2+l/2)*2, ((i-1)/2+(j-1)/2+(l-1)/2)*2+(i*j*l != 0)*3) << "\n";
    return 0;
}
