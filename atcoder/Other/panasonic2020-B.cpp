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
    ll h, w;
    cin >> h >> w;
    if(h == 1 || w == 1){
        cout << 1 << "\n";
    } else if(h%2 && w%2){
        cout << (h*w)/2+1 << "\n";
    }else {
        cout << (h*w)/2 << "\n";
    }
    return 0;
}