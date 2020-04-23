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
    string s, t;
    cin >> s >> t;
    int k = 100*(s == "Sat" || s == "Sun")+(t == "Sat" || t == "Sun");
    if(k == 101){
        puts("8/33");
    }else if(k == 100){
        puts("8/32");
    }else puts("8/31");
    return 0;
}