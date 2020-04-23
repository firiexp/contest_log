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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    ll n;
    cin >> n;
    for (int i = 10; i <= 10000; ++i) {
        ll val = 0, tmp = i, tmp2 = 1;
        while(tmp){
            val += tmp%10*tmp2;
            tmp /= 10;
            if(tmp) tmp2 *= i;
        }
        if(val == n){
            cout << i << "\n";
            return 0;
        }
    }
    puts("-1");
    return 0;
}