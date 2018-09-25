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
    int a, b, c, s;
    cin >> a >> b >> c >> s;
    if((s-a-b-c <= 3)  && (0 <= s-a-b-c)) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}
