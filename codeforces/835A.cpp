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
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int l = 2*t1+v1*s, r = 2*t2+v2*s;
    if(l < r){
        puts("First");
    }else if(l > r){
        puts("Second");
    }else {
        puts("Friendship");
    }
    return 0;
}
