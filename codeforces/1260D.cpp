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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int m, n, k, t;
    cin >> m >> n >> k >> t;
    vector<int> v(m);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end(), greater<>());
    vector<array<int, 3>> Q(k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d", &Q[i][1], &Q[i][2], &Q[i][0]);
    }
    int ans = 0;
    int ok = 0, ng = m+1;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        int val = v[mid-1];
        vector<int> p(n+1);
        for (int i = 0; i < k; ++i) {
            if(Q[i][0] > val){
                p[Q[i][1]-1]++;
                p[Q[i][2]]--;
            }
        }
        int a = 0;
        for (int i = 0; i < n; ++i) {
            p[i+1] += p[i];
            if(p[i]) a++;
        }
        if(a*2+n+1 <= t) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;

}