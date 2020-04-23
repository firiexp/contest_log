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

bool IsKadomatsu(int a, int b, int c){
    if(a == b || b == c || c == a) return false;
    return (max({a, b, c}) == b || min({a, b, c}) == b) && a < c;
}
int main() {
    vector<int> v(7);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    do {
        int ok = 1;
        for (int i = 0; i < 5; ++i) {
            ok &= IsKadomatsu(v[i], v[i+1], v[i+2]);
        }
        if(ok){
            puts("YES");
            return 0;
        }
    }while(next_permutation(v.begin(),v.end()));
    puts("NO");
    return 0;
}