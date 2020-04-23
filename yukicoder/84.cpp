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

int main() {
    ll r, c;
    cin >> r >> c;
    if(r == c){
        if(r%2) cout << (r/2)*(r-r/2) << "\n";
        else cout << (r/2)*(r/2)-1 << "\n";
    }else {
        cout << (r*c+1)/2-1 << "\n";
    }
    return 0;
}
