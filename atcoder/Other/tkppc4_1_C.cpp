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
    ll n; string x;
    cin >> n >> x;
    for (int i = 2; i <= 10; ++i) {
        string y;
        ll nn = n;
        while(nn){
            y += to_string(nn%i);
            nn /= i;
        }
        reverse(y.begin(),y.end());
        if(y == x){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}