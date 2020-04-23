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
    int x;
    cin >> x;
    for (int i = 1; i <= x; ++i) {
        if(x-i*100 <= i*5 && x-i*100 >= 0){
            puts("1");
            return 0;
        }
    }
    puts("0");
    return 0;
}