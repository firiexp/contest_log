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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<u32 M = 1000000007>
struct modint{
    u32 val;
    modint(): val(0){}
    template<typename T>
    modint(T t){t %= (T)M; if(t < 0) t += (T)M; val = t;}

    modint pow(ll k) const {
        modint res(1), x(val);
        while(k){
            if(k&1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }
    template<typename T>
    modint& operator=(T t){t %= (T)M; if(t < 0) t += (T)M; val = t; return *this;}
    modint inv() const {return pow(M-2);}
    modint& operator+=(modint a){val += a.val; if(val >= M) val -= M; return *this;}
    modint& operator-=(modint a){if(val < a.val) val += M-a.val; else val -= a.val; return *this;}
    modint& operator*=(modint a){val = (u64)val*a.val%M; return *this;}
    modint& operator/=(modint a){return (*this) *= a.inv();}
    modint operator+(modint a) const {return modint(val) +=a;}
    modint operator-(modint a) const {return modint(val) -=a;}
    modint operator*(modint a) const {return modint(val) *=a;}
    modint operator/(modint a) const {return modint(val) /=a;}
    modint operator-(){return modint(M-val);}
    bool operator==(const modint a) const {return val == a.val;}
    bool operator!=(const modint a) const {return val != a.val;}
    bool operator<(const modint a) const {return val < a.val;}
};
using mint = modint<MOD>;

using state = string::const_iterator;
using P = array<mint, 3>;

P factor(state &cur);

P term(state &cur){
    auto x = factor(cur);
    while(*cur == '*'){
        cur++;
        auto y = factor(cur);
        x = {x[0]*y[0]+x[1]*y[2]+x[2]*y[1], x[1]*y[1]+x[0]*y[2]+x[2]*y[0], x[2]*y[2]+x[0]*y[1]+x[1]*y[0]};
    }
    return x;
}

P expr(state &cur){
    auto x = term(cur);
    while(true){
        if(*cur == '+'){
            cur++;
            auto y = term(cur);
            x = {x[0]*y[0]+x[0]*y[1]+x[1]*y[0], x[1]*y[1]+x[1]*y[2]+x[2]*y[1], x[2]*y[2]+x[2]*y[0]+x[0]*y[2]};
        }else if(*cur == '-'){
            cur++;
            auto y = term(cur);
            x = {x[0]*y[0]+x[0]*y[2]+x[2]*y[0], x[1]*y[1]+x[1]*y[0]+x[0]*y[1], x[2]*y[2]+x[2]*y[1]+x[1]*y[2]};
        }else break;
    }
    return x;
}


P factor(state &cur) {
    if(*cur == 'R') {
        cur++;
        return {1, 0, 0};
    } else if(*cur == 'S'){
        cur++;
        return {0, 1, 0};
    }else if(*cur == 'P'){
        cur++;
        return {0, 0, 1};
    }else if(*cur == '?'){
        cur++;
        return {1, 1, 1};
    } else if(*cur == '(') {
        cur++;
        P res = expr(cur);
        cur++;
        return res;
    }
    exit(-1);
}


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    state cur = s.begin();
    auto ans = expr(cur);
    char c;
    cin >> c;
    if(c == 'R') printf("%d\n", ans[0].val);
    else if(c == 'S') printf("%d\n", ans[1].val);
    else printf("%d\n", ans[2].val);
    return 0;
}