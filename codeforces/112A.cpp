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
    string s, t;
    cin >> s >> t;
    transform(s.cbegin(), s.cend(), s.begin(), ::tolower);
    transform(t.cbegin(), t.cend(), t.begin(), ::tolower);
    if(s < t){
        puts("-1");
    }else if(s > t){
        puts("1");
    }else puts("0");
    return 0;
}
