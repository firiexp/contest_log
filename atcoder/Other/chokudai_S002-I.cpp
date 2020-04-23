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
    int n;
    cin >> n;
    using P = pair<ll, ll>;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &v[i].first, &v[i].second);
    }
    int a = 0, b = 1;
    while(a < n && b < n){
        int l = (v[a].first+v[b].second-1)/v[b].second -(v[b].first+v[a].second-1)/v[a].second;
        if(l > 0){
            b++;
        }else if(l < 0) a = b, b++;
        else a = b+1, b = b+2;
    }
    if(a >= n){
        puts("-1");
    }else {
        int ok = 1;
        for (b = 0; b < n; ++b) {
            if(b != a){
                if((v[a].first+v[b].second-1)/v[b].second <= (v[b].first+v[a].second-1)/v[a].second) ok = 0;
            }
        }
        if(ok) cout << a+1 << "\n";
        else puts("-1");
    }
    return 0;
}