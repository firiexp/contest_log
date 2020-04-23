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

static constexpr int MOD = 998244353;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

using state = string::const_iterator;

using P = pair<ll, ll>;

P num(state &cur){
    P res = {0, -1};
    while(isdigit(*cur)) res.first = (res.first*10+*(cur++)-'0')%MOD;
    return res;
}

P f(P a, P b){
    if(!(~a.second) && !(~b.second)) return {a.first*b.first%MOD, -1};
    else if(!(~a.second)) return {a.first*b.first%MOD, a.first*b.second%MOD};
    else if(!(~b.second)) return {a.first*b.first%MOD, b.first*a.second%MOD};
    else return {(a.first*b.first+a.second*b.second)%MOD, -1};
}

P expr(state &cur){
    if(isdigit(*cur)) return num(cur);

    if(*cur == '(') {
        cur++;
        P res = expr(cur);
        if(*cur == ','){
            cur++;
            res.second = expr(cur).first;
        }else if(*cur == '*'){
            cur++;
            res = f(res, expr(cur));
        }
        cur++;
        return res;
    }
    exit(1);
}

int main() {
    string s;
    cin >> s;
    state cur = s.begin();
    auto res = expr(cur);
    cout << res.first << "\n";
    return 0;
}