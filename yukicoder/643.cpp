#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int f(int x, int y){
    if(x == y) return 0;
    else if(y == 0) return 1;
    else if(x == 0) return 2;
    else if(x == -y) return 3;
    else return -1;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << f(x, y) << "\n";
    return 0;
}
