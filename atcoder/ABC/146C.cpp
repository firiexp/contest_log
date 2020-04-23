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
    ll a, b, x;
    cin >> a >> b >> x;
    ll ok = 0, ng = 1000000001;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        if(a*mid + to_string(mid).size()*b <= x) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}