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

using state = string::const_iterator;

string expr(state &cur, string t = ""){
    int v = 0;
    while(true){
        if(isalpha(*cur)){
            t += (char)((*cur-'A'+v+260)%26+'A');
            cur++;
            v = 0;
        } else if(*cur == '?') {
            t += 'A';
            cur++;
            v = 0;
        } else if(*cur == '+') {
            v++;
            cur++;
        } else if(*cur == '-') {
            v--;
            cur++;
        } else if(*cur == '[') {
            cur++;
            string u = expr(cur);
            reverse(u.begin(),u.end());
            t += u;
            cur++;
        }else break;
    }
    return t;
}

int main() {
    string s;
    while(cin >> s, s != "."){
        state cur = s.begin();
        string t = expr(cur), ans;
        int v = 0;
        for (auto &&i : t) {
            if(isalpha(i)) ans += (char)((i-'A'+v+26)%26+'A'), v = 0;
            else if(i == '?') ans += 'A', v = 0;
            else if(i == '+') v++;
            else v--;
        }
        cout << ans << "\n";
    }
    return 0;
}