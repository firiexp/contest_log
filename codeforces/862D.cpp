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
#include <assert.h>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    int a, b;
    cout << "? " << string(n, '0') << endl;
    cin >> a; a = n-a;
    cout << "? " << '1' << string(n-1, '0') << endl;
    cin >> b; b = n-b;
    if(a < b){ // s[0] == 1
        int ok = 1, ng = n;
        int p = 0;
        while(ng-ok > 1){
            int mid = (ok+ng)/2;
            cout << "? " << string(mid, '1') << string(n-mid, '0') << endl;
            cin >> p; p = n-p;
            if((mid+p-a)%2) assert(0);
            if((mid+p-a)/2 == mid) ok = mid;
            else ng = mid;
        }
        cout << "! " << ng << " " << 1 << endl;
    }else {
        int ok = 1, ng = n;
        int p = 0;
        while(ng-ok > 1){
            int mid = (ok+ng)/2;
            cout << "? " << string(mid, '1') << string(n-mid, '0') << endl;
            cin >> p; p = n-p;
            if((mid+a-p)%2) assert(0);
            if((mid+a-p)/2 == mid) ok = mid;
            else ng = mid;
        }
        cout << "! " << 1 << " " << ng << endl;
    }
    return 0;
}