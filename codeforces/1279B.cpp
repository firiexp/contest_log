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

int solve(){
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<ll> S(n+1), M(n+1, 0);
    for (int i = 0; i < n; ++i) S[i+1] = S[i] + v[i], M[i+1] = max<ll>(M[i], v[i]);
    if(S.back() <= s) return 0;
    int ok = 0, ng = n+1;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        if(S[mid] - M[mid] <= s) ok = mid;
        else ng = mid;
    }
    if(ok == 0) return 0;
    return max_element(v.begin(),v.begin()+ok) - v.begin() + 1;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        cout << solve() << "\n";
    }
    return 0;
}