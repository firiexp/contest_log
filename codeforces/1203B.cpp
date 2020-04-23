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

bool solve(){
    int n;
    cin >> n;
    vector<int> v(4*n), u(2*n);
    for (auto &&j : v) scanf("%d", &j);
    sort(v.begin(),v.end());
    for (int i = 0; i < 2*n; ++i) {
        if(v[2*i] != v[2*i+1]){
            return false;
        }
        u[i] = v[2*i];
    }
    int k = u.front()*u.back();
    for (int i = 0; i < n; ++i) {
        if(u[i]*u[2*n-i-1] != k) return false;
    }
    return true;
}

int main() {
    int q;
    cin >> q;
    while(q--){
        puts(solve() ? "YES" : "NO");
    }
    return 0;
}