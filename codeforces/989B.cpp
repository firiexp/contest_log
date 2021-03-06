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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    int good = 0;
    for (int i = 0; i+p < n; ++i) {
        if(s[i] == '.' && s[i+p] == '.'){
            good = 1;
            s[i] = '0';
            s[i+p] = '1';
        }else if(s[i] == '.'){
            good = 1;
            s[i] = s[i+p]^1;
        }else if(s[i+p] == '.'){
            good = 1;
            s[i+p] = s[i]^1;
        }else if(s[i] != s[i+p]){
            good = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(s[i] == '.') s[i] = '0';
    }
    if(!good) {
        puts("No");
        return 0;
    }
    cout << s << "\n";
    return 0;
}