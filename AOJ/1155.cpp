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


int formula(state &cur);

int factor(state &cur){
    if(*cur == '-'){
        cur++;
        return 2-factor(cur);
    }
    if(isdigit(*cur)) {
        return *(cur++)-'0';
    }
    cur++;
    int ans = formula(cur);
    cur++;
    return ans;
}



int formula(state &cur) {
    int ans = factor(cur);
    while(true){
        if(*cur == '*'){
            cur++;
            ans = min(ans, factor(cur));
        }else if(*cur == '+'){
            cur++;
            ans = max(ans, factor(cur));
        }else break;
    }
    return ans;
}


int main() {
    string s;
    while(cin >> s, s != "."){
        int ans = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    string t = s;
                    for (auto &&l : t) {
                        if(l == 'P') l = '0'+i;
                        if(l == 'Q') l = '0'+j;
                        if(l == 'R') l = '0'+k;
                    }
                    state cur = t.begin();
                    if(formula(cur) == 2) ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}