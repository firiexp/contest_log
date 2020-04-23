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
    int a = s[0]-'0', b = s[1]-'0' + (s[2] >= '5'), c = s.size()-1;
    if(b >= 10) a++, b -= 10;
    if(a >= 10) {
        c++;
        b = a%10;
        a = a/10;
    }
    printf("%d.%d*10^%d\n", a, b, c);
    return 0;
}
