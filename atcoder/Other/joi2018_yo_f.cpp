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
    int n, k; ll l;
    cin >> n >> k >> l;
    int ok = 0, ng = n+1;
    vector<int> v(n), u(n);
    for (auto &&i : v) scanf("%d", &i);
    while(ng-ok > 1){
        int X = (ok+ng)/2;
        for (int i = 0; i < n; ++i) u[i] = v[i] < X;
        int lcur = 0, rcur = 0, cnt = 0;
        ll val = 0;
        while(rcur < n){
            cnt += u[rcur++];
            while(cnt >= k) cnt -= u[lcur++];
            if(rcur >= k) val += min(rcur-k+1, lcur);
        }
        if(val < l) ok = X;
        else ng = X;
    }
    cout << ok << "\n";
    return 0;
}