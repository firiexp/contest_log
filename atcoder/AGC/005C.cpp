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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    map<int, int> m;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        m[v[i]]++;
    }
    int mx = v.back();
    if(v.front() < (mx+1)/2){
        puts("Impossible");
        return 0;
    }
    if(mx%2 == 0 && m[mx/2] != 1){
        puts("Impossible");
        return 0;
    }else if(mx%2 && m[(mx+1)/2] != 2){
        puts("Impossible");
        return 0;
    }
    for (int i = mx-(mx+1)/2+1; i <= mx; ++i) {
        if(m[i] < 2){
            puts("Impossible");
            return 0;
        }
    }
    puts("Possible");
    return 0;
}
