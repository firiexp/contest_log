#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int l = 0, r = MOD;
    while(r-l > 1){
        int mid = (l+r)/2;
        cout << "? " << mid << endl;
        int t;
        cin >> t;
        if(t == 1) l = mid;
        else r = mid;
    }
    cout << "! " << l << endl;
    return 0;
}
