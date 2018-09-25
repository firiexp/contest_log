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
    string dirs[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
                     "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
    int p[] = {3, 16, 34, 55, 80, 108, 139, 172, 208, 245, 285, 327};
    int a, b;
    cin >> a >> b;
    a *= 10;
    a = (a + 1125) % 36000;
    int ans = 0;
    b = (b+3)/6;
    for (auto &&x : p) {
        if(x <= b) ans++;
    }
    if(ans == 0){
        cout << "C 0\n";
    }else {
        cout << dirs[a/2250] << " " << ans << "\n";
    }
    return 0;
}
