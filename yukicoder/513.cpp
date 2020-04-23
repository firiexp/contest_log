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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int l = 0, r = 100001, ans1 = 0;
    while(r-l > 1){
        int mid = (r+l)/2;
        cout << mid << " " << 0 << endl;
        int val1; cin >> val1;
        if(val1 == 0) return 0;
        cout << mid-1 << " " << 0 << endl;
        int val2; cin >> val2;
        if(val2 == 0) return 0;
        if(val1 < val2) l = mid;
        else r = mid;
    }
    ans1 = l, l = 0, r = 100001;
    while(r-l > 1){
        int mid = (r+l)/2;
        cout << ans1 << " " << mid << endl;
        int val1; cin >> val1;
        if(val1 == 0) return 0;
        cout << ans1 << " " << mid-1 << endl;
        int val2; cin >> val2;
        if(val2 == 0) return 0;
        if(val1 < val2) l = mid;
        else r = mid;
    }
    return 0;
}
