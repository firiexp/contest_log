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
    int y, m, d;
    cin >> y >> m >> d;
    if(m == 12 && d == 25){
        cout << y-2018 << "\n";
    }else {
        cout << "NOT CHRISTMAS DAY" << "\n";
    }
    return 0;
}
