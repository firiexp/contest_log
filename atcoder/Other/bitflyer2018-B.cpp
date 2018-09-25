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
    int a, b, n;
    string s;
    cin >> a >> b >> n >> s;
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'S' && a) a--;
        if(s[i] == 'C' && b) b--;
        if(s[i] == 'E' && (a||b)){
            if(a < b) b--;
            else a--;
        }
    }
    cout << a << "\n" << b << "\n";
    return 0;
}
