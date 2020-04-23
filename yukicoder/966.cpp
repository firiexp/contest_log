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

bool IsKadomatsu(ll  a, ll b, ll c){
    if(min({a, b, c}) <= 0) return false;
    if(a == b || b == c || c == a) return false;
    return max({a, b, c}) == b || min({a, b, c}) == b;
}

int main() {
    int t;
    cin >> t;
    ll d = 1, a, b, c, x, y, z;
    while(t--){
        cin >> x >> y >> z;
        cin >> a >> b >> c;
        ll ans = INF<ll>;
        vector<ll> A{x, x+1, x+2, y, y+1, y+2, z, z+1, z+2};
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        for (int i = 0; i < A.size(); ++i) {
            if(x > A[i]) continue;
            for (int j = 0; j < A.size(); ++j) {
                if(y > A[j]) continue;
                if(A[i] == A[j]) continue;
                for (int k = 0; k < A.size(); ++k) {
                    if(z > A[k]) continue;
                    ll p = -(x-A[i]+y-A[j]+z-A[k]);
                    if(IsKadomatsu(A[i]-p, A[j]-p, A[k]-p)){
                        ans = min(ans, (A[i]-x)*b+(A[j]-y)*c+(A[k]-z)*a);
                    }
                }
            }
        }
        if(ans == INF<ll>) puts("-1");
        else cout << ans << "\n";
    }
    return 0;
}