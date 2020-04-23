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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

using state = string::const_iterator;

int num(state &cur);
int factor(state &cur);
int muldiv(state &cur);
int addsub(state &cur);
int expr(state &cur);

int factor(state &cur) {
    if(isdigit(*cur)) return num(cur);
    cur++;
    int ans = addsub(cur);
    cur++;
    return ans;
}

int num(state &cur) {
    int ans = *cur -'0';
    while(isdigit(*++cur)) ans = ans*10 + (*cur-'0');
    return ans;
}

int muldiv(state &cur) {
    int ans = factor(cur);
    while(true){
        if(*cur == '*'){
            cur++;
            ans *= factor(cur);
        }else if(*cur == '/'){
            cur++;
            ans /= factor(cur);
        }else break;
    }
    return ans;
}

int addsub(state &cur){
    int ans = muldiv(cur);
    while(true){
        if(*cur == '+'){
            cur++;
            ans += muldiv(cur);
        }else if(*cur == '-'){
            cur++;
            ans -= muldiv(cur);
        }else break;
    }
    return ans;
}

int expr(state &cur){
    return addsub(cur);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        state cur = s.begin();
        cout << expr(cur) << "\n";
    }
    return 0;
}
