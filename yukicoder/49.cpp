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

int num(state &cur){
    int ans = *cur++ - '0';
    while(isdigit(*cur)) ans = ans*10+(*cur++ -'0');
    return ans;
}

int expr(state &cur){
    int ans = num(cur);
    while(true){
        if(*cur == '+'){
            cur++;
            ans *= num(cur);
        }else if(*cur == '*'){
            cur++;
            ans += num(cur);
        }else break;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    state it = s.begin();
    cout << expr(it) << "\n";
    return 0;
}
