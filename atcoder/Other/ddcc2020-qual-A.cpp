#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    if(x == 1 && y == 1){
        ans = 1000000;
    }else {
        ans = 100000*(max(4-x, 0) + max(4-y, 0));
    }
    cout << ans << "\n";
    return 0;
}