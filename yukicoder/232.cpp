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
    int T, A, B;
    cin >> T >> A >> B;
    if(T < A || T < B || (T == 1 && A == 0 && B == 0)){
        puts("NO");
        return 0;
    }
    puts("YES");
    string s(A, '^'), t(B, '>');
    while(s.size()*2 < T && s.size()+t.size() < T) s += "^v";
    while(t.size()*2 < T && s.size()+t.size() < T) t += "<>";
    for (int i = 0; i < T; ++i) {
        if(s.size() + t.size() > T-i){
            cout << s.back() << t.back() << "\n"; s.pop_back(); t.pop_back();
        }else if(!s.empty()){
            cout << s.back() << "\n"; s.pop_back();
        }else {
            cout << t.back() << "\n"; t.pop_back();
        }
    }
    return 0;
}