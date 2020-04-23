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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    string s;
    cin >> n >> s;
    if(s.back() == '?') s.back() = ')';
    if(s.front() == '?') s.front() = '(';
    if(s.front() == ')') {
        puts(":(");
        return 0;
    }
    if(n%2){
        puts(":(");
        return 0;
    }
    if(s.back() == '('){
        puts(":(");
        return 0;
    }
    int a = (n-2)/2, b = (n-2)/2;
    for (int i = 1; i < n-1; ++i) {
        if(s[i] == '(') a--;
        else if(s[i] == ')') b--;
    }
    for (int i = 1; i < n-1; ++i) {
        if(s[i] == '?') {
            if(a > 0) a--, s[i] = '(';
            else b--, s[i] = ')';
        }
    }
    int dep = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '(') dep++;
        else dep--;
        if(dep <= 0 && i != n-1){
            puts(":(");
            return 0;
        }
    }
    if(dep != 0){
        puts(":(");
        return 0;
    }
    cout << s << "\n";
    return 0;
}
