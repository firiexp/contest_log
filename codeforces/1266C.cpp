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
    int r, c;
    cin >> r >> c;
    if(r == 1 && c == 1){
        puts("0");
        return 0;
    }
    int ok = 0;
    if(r > c) ok = 1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(j) printf(" ");
            if(!ok) printf("%d", (i+1)*(j+1+r));
            else printf("%d", (i+1+c)*(j+1));
        }
        puts("");
    }
    return 0;
}