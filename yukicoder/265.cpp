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

using ar = array<ll, 11>;

using state = string::const_iterator;

ar num(state &cur);
ar add(state &cur);

ar factor(state &cur){
    if(*cur == 'x' || isdigit(*cur)) return num(cur);
    cur++; cur++;
    ar ret = add(cur);
    for (int i = 0; i < 10; ++i) {
        ret[i] = ret[i+1]*(i+1);
    }
    ret[10] = 0;
    cur++;
    return ret;
}

ar num(state &cur){
    ar ret{};
    if(isdigit(*cur)) ret[0] = *cur-'0';
    else ret[1] = 1;
    cur++;
    return ret;
}

ar mul(state &cur){
    ar ret = factor(cur);
    while(true){
        if(*cur == '*'){
            cur++;
            ar rett = factor(cur);
            if(rett[0]){
                for (int i = 0; i < 11; ++i) ret[i] *= rett[0];
            }else {
                for (int i = 9; i >= 0; --i) ret[i+1] = ret[i];
                ret[0] = 0;
            }

        }else break;
    }
    return ret;
}

ar add(state &cur){
    ar ret = mul(cur);
    while(true){
        if(*cur == '+'){
            cur++;
            ar x = mul(cur);
            for (int i = 0; i < 11; ++i) ret[i] += x[i];
        }else break;
    }
    return ret;
}


int main() {
    int n, d; string s;
    cin >> n >> d >> s;
    state ss = s.begin();
    auto ret = add(ss);
    for (int i = 0; i < d+1; ++i) {
        if(i) printf(" ");
        printf("%lld", ret[i]);
    }
    puts("");
    return 0;
}