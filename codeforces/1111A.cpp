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

int main() {
    string s, t;
    cin >> s >> t;
    auto f = [&](char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    if(s.size() != t.size()){
        puts("No");
    }else {
        for (int i = 0; i < s.size(); ++i) {
             if(f(s[i]) != f(t[i])) {
                 puts("No");
                 return 0;
             }
        }
        puts("Yes");
    }
    return 0;
}