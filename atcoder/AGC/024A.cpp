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
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if(k%2){
        cout << b-a << "\n";
    }else cout << a-b << "\n";
    return 0;
}
