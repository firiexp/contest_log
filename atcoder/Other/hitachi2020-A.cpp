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
    string s;
    cin >> s;
    if(s.size()%2){
        puts("No");
        return 0;
    }
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if(i%2 == 0 && s[i] != 'h'){
            puts("No");
            return 0;
        }
        if(i%2 == 1 && s[i] != 'i'){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}