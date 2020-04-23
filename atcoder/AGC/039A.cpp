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
    string s; ll k;
    cin >> s >> k;
    int n = s.size();
    int ok = 1;
    for (int i = 0; i < n-1; ++i) {
        if(s[i] != s[i+1]) ok = 0;
    }
    if(ok){
        cout << n*k/2 << "\n";
        return 0;
    }
    if(s.front() == s.back()){
        ll ans = 0, ans2 = 0, a = 0, b = 0;
        s += s;
        s += "?";
        int cur = 0;
        while(cur < n){
            int curr = cur;
            auto c = s[cur];
            while(c == s[curr]) curr++;
            if(cur == 0){
                a += (curr-cur)/2;
            }else if(curr >= n){
                b += (n-cur)/2;
                ans2 += (curr-cur)/2;
            }else {
                ans += (curr-cur)/2;
            }
            cur = curr;
        }
        cout << ans*k + ans2*(k-1)+a+b << "\n";
    }else {
        ll ans = 0;
        s += s;
        s += "?";
        int cur = 0;
        while(cur < n){
            int curr = cur;
            auto c = s[cur];
            while(c == s[curr]) curr++;
            ans += (curr-cur)/2;
            cur = curr;
        }
        cout << ans*k << "\n";
    }

    return 0;
}