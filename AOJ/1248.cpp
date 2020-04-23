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
    int a, b, c;
    while(cin >> a >> b >> c, a){
        ll ans1 = INF<int>, ans2 = INF<int>, ans3 = INF<ll>;
        for (int x = 0; x <= 100000; x++) {
            ll k = a*x+c;
            if(k%b == 0){
                ll y = k/b;
                if(x+y < ans1+ans2){
                    ans1 = x, ans2 = y, ans3 = a*x+b*y;
                }else if(x+y == ans1+ans2 && a*x+b*y < ans3){
                    ans1 = x, ans2 = y, ans3 = a*x+b*y;
                }
            }
            k = a*x-c;
            if(k%b == 0 && k >= 0){
                ll y = k/b;
                if(x+y < ans1+ans2){
                    ans1 = x, ans2 = y, ans3 = a*x+b*y;
                }else if(x+y == ans1+ans2 && a*x+b*y < ans3){
                    ans1 = x, ans2 = y, ans3 = a*x+b*y;
                }
            }
            k = c-a*x;
            if(k%b == 0 && k >= 0){
                ll y = k/b;
                if(x+y < ans1+ans2){
                    ans1 = x, ans2 = y, ans3 = a*x+b*y;
                }else if(x+y == ans1+ans2 && a*x+b*y < ans3){
                    ans1 = x, ans2 = y, ans3 = a*x+b*y;
                }
            }
        }
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}