#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

using state = string::const_iterator;
int p;

template<typename T>
T mod_inv(T x, T M){
   T u = 1, t = 1, v = 0, s = 0, m = M;
   while (x) { T q = m/x; swap(s -= q*u, u); swap(t -= q*v, v); swap(m -= q*x, x); }
   if(s < 0) s += M;
   return s;
}

int expr(state &cur);

int num(state &cur){
    if(isdigit(*cur)){
        int res = 0;
        while(isdigit(*cur)) res = res*10+(*(cur++)-'0');
        return res;
    }else if(*cur == '('){
        cur++;
        int res = expr(cur);
        if(!~res) return -1;
        cur++;
        return res;
    }
    exit(1);
}

int term(state &cur){
    auto res = num(cur);
    if(!~res) return -1;
    while(true){
        if(*cur == '*'){
            cur++;
            auto y = num(cur);
            if(!~y) return -1;
            (res *= y) %= p;
        }else if(*cur == '/'){
            cur++;
            auto y = num(cur);
            if(!~y || !y) return -1;
            (res *= mod_inv(y, p)) %= p;
        }else break;
    }
    return res;
}

int expr(state &cur) {
    auto res = term(cur);
    if(!~res) return -1;
    while(true){
        if(*cur == '+'){
            cur++;
            auto y = term(cur);
            if(!~y) return -1;
            res += y;
            if(res >= p) res -= p;
        }else if(*cur == '-'){
            cur++;
            auto y = term(cur);
            if(!~y) return -1;
            res -= y;
            if(res < 0) res += p;
        }else break;
    }
    return res;
}

int main() {
    string s;
    while(getline(cin, s), s != "0:"){
        string t;
        p = 0;
        int f = 0;
        for (auto &&i : s) {
            if(i == ':') f = 1;
            else if(!f) {
                p = p*10+(i-'0');
            }else if(i != ' ') t += i;
        }
        state cur = t.begin();
        auto ans = expr(cur);
        if(!~ans) puts("NG");
        else cout << t << " = " << ans << " (mod " << p << ")\n";
    }
    return 0;
}