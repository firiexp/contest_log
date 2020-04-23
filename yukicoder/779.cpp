#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int y, m, d;
    cin >> y >> m >> d;
    bool ans = false;
    if(1990 <= y && y <= 2018) ans = true;
    else if(y == 1989){
        if(!(m == 1 && d <= 7)) ans = true;
    }else if(y == 2019){
        if(m <= 4) ans = true;
    }
    puts(ans ? "Yes" : "No");
    return 0;
}
