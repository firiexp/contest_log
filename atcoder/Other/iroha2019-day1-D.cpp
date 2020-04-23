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

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(),v.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        (i%2 == 0 ? x : y) += v[i];
    }
    if(x > y){
        puts("Takahashi");
    }else if(x < y){
        puts("Aoki");
    }else {
        puts("Draw");
    }
    return 0;
}