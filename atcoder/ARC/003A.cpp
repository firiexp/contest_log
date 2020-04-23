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
    string s;
    cin >> n >> s;
    long double sum = 0;
    for (auto &&i : s) {
        if('A' <= i && i <= 'D') sum += 'E'-i;
    }
    cout << setprecision(15) << sum/n << "\n";
    return 0;
}
