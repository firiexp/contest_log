#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int y, m, d;
    cin >> y >> m >> d;
    if(m <= 2){
        y--;
        m += 12;
    }
    cout << 735369 - (365*y+y/4-y/100+y/400+306*(m+1)/10+d-429) << "\n";
    return 0;
}
