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
    if(a <= 5){
        puts("0");
    }else if(a <= 12){
        cout << b/2 << "\n";
    }else {
        cout << b << "\n";
    }
    return 0;
}