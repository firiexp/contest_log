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

int main() {
    string s;
    cin >> s;
    int m3 = 0, m5 = 0, b = -1;
    for (auto &&i : s) {
        m3 += (i-'0');
        m5 += (i-'0')*b;
        b *= -1;
    }
    m3 = (m3 + 999999) % 3;
    m5 = (m5 + 1000000) % 5;
    if(m3 == 0 && m5 == 0){
        puts("FizzBuzz");
    }else if(m3 == 0){
        puts("Fizz");
    }else if(m5 == 0){
        puts("Buzz");
    }else {
        puts(s.c_str());
    }
    return 0;
}
