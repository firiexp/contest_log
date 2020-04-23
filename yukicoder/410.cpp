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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << setprecision(10) << (abs(a-c)+abs(b-d))/2.0 << "\n";
    return 0;
}
