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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
            puts("-1");
        }else {
            for (int i = 0; i < n-1; ++i) {
                printf("3");
            }
            printf("4");
            puts("");
        }
    }
    return 0;
}