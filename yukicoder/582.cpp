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
    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x != 0) v.emplace_back(x), cnt++;
    }
    n = cnt;
    sort(v.begin(), v.end());
    if(n >= 1 && v[n-1] == 1 && (n&1) == 1){
        puts("A");
        return 0;
    }else if(n >= 2 && v[n-1] == 2 && v[n-2] == 1 && (n&1) == 0){
        puts("A");
        return 0;
    }
    puts("B");
    return 0;
}
