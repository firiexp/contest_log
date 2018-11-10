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
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == '8') a++;
        b++;
    }
    int ans = 0;
    while(b >= 11 & a > 0){
        b -= 11;
        a--;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
