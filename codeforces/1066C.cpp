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
    int q;
    cin >> q;
    int l = 0, r = 1;
    vector<int> v(200001);
    while(q--){
        char c; int x;
        scanf(" %c %d", &c, &x);
        if(c == 'L'){
            v[x] = l--;
        }else if(c == 'R'){
            v[x] = r++;
        }else {
            printf("%d\n", min(v[x]-l-1, r-v[x]-1));
        }
    }

    return 0;
}