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
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    s = "##" + s + "##";
    a++; b++; c++; d++;
    if(c < d){
        int ok = 1;
        while(b < d){
            if(s[b+1] == '.') b++;
            else if(s[b+2] == '.') b += 2;
            else {
                ok = 0;
                break;
            }
        }
        while(a < c){
            if(s[a+1] == '.') a++;
            else if(s[a+2] == '.') a += 2;
            else {
                ok = 0;
                break;
            }
        }
        if(ok == 0){
            puts("No");
        }else {
            puts("Yes");
        }
    }else {
        int ok = 1;
        while(b < d){
            if(s[b-1] == '.' && s[b+1] == '.') break;
            if(s[b+1] == '.') b++;
            else if(s[b+2] == '.') b += 2;
            else {
                ok = 0;
                break;
            }
            if(s[b-1] == '.' && s[b+1] == '.') break;
        }
        s[b] = '#';
        while(a < c){
            if(s[a+1] == '.') a++;
            else if(s[a+2] == '.') a += 2;
            else {
                ok = 0;
                break;
            }
        }
        while(b < d){
            if(s[b+1] == '.') b++;
            else if(s[b+2] == '.') b += 2;
            else {
                ok = 0;
                break;
            }
        }
        if(ok == 0){
            puts("No");
        }else {
            puts("Yes");
        }
    }
    return 0;
}