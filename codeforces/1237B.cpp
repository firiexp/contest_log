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
    vector<int> a(n), b(n);
    for (auto &&i : a) scanf("%d", &i), i--;
    for (auto &&j : b) scanf("%d", &j), j--;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    vector<int> v(n);
    int ans = 0, p = 0, q = 0;
    while(p < n && q < n){
        if(v[b[q]] == -1) q++;
        else if(a[p] == b[q]){
            p++;
            q++;
        } else if(!v[a[p]]){
            v[a[p]] = -1;
            p++;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}