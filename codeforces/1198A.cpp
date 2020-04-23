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
    int n, m;
    cin >> n >> m;
    ll BIT = 8*m/n;
    ll k;
    if(BIT > 31) k = INF<int>;
    else k = 1LL<<BIT;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    int ans = 0;
    {
        int l = 0, r = 0, val = 0;
        while(r < n){
            if(r == 0 || (v[r-1] != v[r])) val++;
            r++;
            while(l < r && val > k){
                if(r-l == 1 || (v[l] != v[l+1])) val--;
                l++;
            }
            ans = max(ans, r-l);
        }
    }
    cout << n-ans << "\n";
    return 0;
}