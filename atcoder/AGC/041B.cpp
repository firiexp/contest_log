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

int main() {
    int n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<int> A(n);
    for (auto &&i : A) scanf("%d", &i);
    sort(A.begin(),A.end(), greater<>());
    int ok = -1, ng = n;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        vector<pair<ll, ll>> val(n);
        ll S = 0;
        for (int i = 0; i < n; ++i) val[i].second = i;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if(i == mid) continue;
            if(A[i] <= A[mid] + m){
                S += min(m, A[mid] - A[i] + m);
                val[i].first = min(m, A[mid] - A[i] + m);
            }else {
                S += m, cnt++;
                val[i].first = m;
            }

        }
        sort(val.begin(),val.end());
        for (int i = 0; i < n; ++i) {
            if(val[i].second == mid) continue;
            if(S >= (ll)(v-1)*m) continue;
            S += m - val[i].first;
            cnt++;
        }
        if(cnt < p) ok = mid;
        else ng = mid;
    }
    cout << ok+1 << "\n";
    return 0;
}