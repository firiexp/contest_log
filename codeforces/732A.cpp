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
    int k, r;
    cin >> k >> r;
    for (int i = 1; i <= 10; ++i) {
        if(k*i%10 == 0 || k*i%10 == r){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}