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
    int n;
    cin >> n;
    vector<int> v(1442, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d-%d", &a, &b);
        while(a%5 != 0) a--;
        while(b%5 != 0) b++;
        a = a%100+(a/100)*60, b = b%100+(b/100)*60;
        v[a]++; v[b+1]--;
    }
    for (int i = 1; i < 1442; ++i) v[i] += v[i-1];
    int l = 0;
    while(l < 1442){
        if(v[l] <= 0) l++;
        else {
            int r = l+1;
            while(v[r] >= 1 && r < 1442) r++;
            printf("%02d%02d-%02d%02d\n", l/60, l%60, (r-1)/60, (r-1)%60);
            l = r;
        }
    }
    return 0;
}
