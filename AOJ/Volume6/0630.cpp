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
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    ll t = 0;
    while(a < b){
        if(a < 0) a++, t += c;
        else if(a == 0) a++, t += d+e;
        else a++, t += e;
    }
    cout << t << "\n";
    return 0;
}