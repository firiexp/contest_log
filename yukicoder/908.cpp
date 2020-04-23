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
    string s;
    getline(cin, s);
    int ok = 1;
    for (int i = 0; i < s.size(); ++i) {
        if(i&1){
            if(s[i] != ' ') ok = 0;
        }else {
            if(!islower(s[i])) ok = 0;
        }
    }
    puts(ok ? "Yes" : "No");
    return 0;
}