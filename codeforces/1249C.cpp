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
    int q;
    cin >> q;
    while(q--){
        ll n; scanf("%lld", &n);
        string s;
        while(n){
            s += '0' + (n%3);
            n /= 3;
        }
        reverse(s.begin(),s.end());
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == '2'){
                int j = i;
                while(j >= 0 && s[j] >= '1') j--;
                if(j == -1){
                    s =  '1' + string(s.size(), '0');
                }else {
                    s[j] = '1';
                    for (int k = j+1; k < s.size(); ++k) {
                        s[k] = '0';
                    }
                }
                break;
            }
        }
        reverse(s.begin(),s.end());
        ll ans = 0, k = 1;
        for (int i = 0; i < s.size(); ++i) {
            ans += (s[i]-'0')*k;
            k *= 3;
        }
        cout << ans << "\n";
    }
    return 0;
}