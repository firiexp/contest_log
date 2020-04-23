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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int a, b;
    cin >> a >> b;
    int x = 0, y = 0, z = 0;
    for (int i = 1; i <= 6; ++i) {
        if(abs(i-a) < abs(i-b)) x++;
        else if(abs(i-a) > abs(i-b)) z++;
        else y++;
    }
    cout << x  << " " << y << " " << z << "\n";
    return 0;
}