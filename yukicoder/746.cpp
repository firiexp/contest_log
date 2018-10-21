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
    string s = "0", t = "142857";
    if(n == 0){
        cout << s << "\n";
        return 0;
    }
    s += ".";
    for (int i = 0; i < n; ++i) {
        s += t[i%6];
    }
    cout << s << "\n";
    return 0;
}
