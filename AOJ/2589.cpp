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
    string s;
    while(cin >> s, s != "#"){
        ll a = 0, b = 1;
        int k = 1, cur = 0;
        reverse(s.begin(),s.end());
        if(s[cur] == 'h'){
            a = 0;
            cur += 5;
        }else {
            a = 90;
            cur += 4;
        }

        while(cur < s.size()){
            if(s[cur] == 'h'){
                a = ((1<<k)*a-90*b), b = (1<<k)*b;
                ll g = __gcd(a, b);
                a /= g, b /= g;
                cur += 5;
            }else {
                a = ((1<<k)*a+90*b), b = (1<<k)*b;
                ll g = __gcd(a, b);
                a /= g, b /= g;
                cur += 4;
            }
            k++;
        }
        printf("%lli", a);
        if(b != 1) printf("/%lli", b);
        puts("");
    }
    return 0;
}