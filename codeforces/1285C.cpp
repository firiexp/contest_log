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

template<class T>
vector<T> divisor(T n){
    vector<T> ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}

int main() {
    ll x;
    cin >> x;
    auto v = divisor(x);
    vector<int> u(v.size(), 0);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if(v[i]%v[j] == 0){
                u[i] = max(u[i], j);
            }
        }
    }
    map<ll, int> pff;
    int curr = v.size()-1;
    while(curr != 0){
        pff[v[curr]/v[u[curr]]]++;
        curr = u[curr];
    }
    ll ans1 = x, ans2 = 1;
    for (int i = 0; i < v.size(); ++i) {
        map<ll, int> pf;
        int cur = i;
        while(cur != 0){
            pf[v[cur]/v[u[cur]]]++;
            cur = u[cur];
        }
        ll val = 1;
        for (auto &&j : pff) {
            if(pf[j.first] < j.second){
                for (int k = 0; k < j.second; ++k) {
                    val *= j.first;
                }
            }
        }
        if(max(ans1, ans2) > max(v[i], val)){
            ans1 = v[i], ans2 = val;
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}