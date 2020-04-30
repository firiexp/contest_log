#include <iostream>
#include <algorithm>
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
    int n;
    while(cin >> n, n){
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            if(x == 1) count1++;
            else if(x >= 2) count2++;
        }
        if(!count2) puts("NA");
        else cout << count1+count2+1 << "\n";
    }
    return 0;
}