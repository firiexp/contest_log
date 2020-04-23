#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    double x;
    while(cin >> x, x >= 0){
        int val = int(x*16);
        if(x == val/16.0 && val < 4096){
            cout << bitset<8>(val >> 4) << "." << bitset<4>(val&15) << "\n";
        }else puts("NA");
    }
    return 0;
}