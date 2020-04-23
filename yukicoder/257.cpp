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
    int n, k;
    cin >> n >> k;
    cout << (n-1)%(k+1) << endl;
    while(true){
        int x;
        cin >> x;
        if(x >= n){
            return 0;
        }
        cout << x+(n-x-1)%(k+1) << endl;
    }
    return 0;
}
