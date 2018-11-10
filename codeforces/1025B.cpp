#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using ll = long long;
using namespace std;
using P = pair<int, int>;

set<ll> prime_factor(ll n)
{
    set<ll> ret;
    for(ll i = 2; i * i <= n; i++){
        while(n % i == 0) {
            ret.emplace(i);
            n /= i;
        }
    }
    if(n != 1) ret.emplace(n);
    return(ret);
}


int main() {
    int n;
    cin >> n;
    vector<P> v;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());
    P p = v.front();
    set<ll> a, b;
    vector<int> v2;
    a = prime_factor(p.first);
    b = prime_factor(p.second);
    set_union(a.begin(), a.end(),
              b.begin(), b.end(),
              inserter(v2,v2.end()));
    for (auto &&x : v2) {
        int t = 1;
        for (int i = 0; i < n; ++i) {
            int e = v[i].first, w = v[i].second;
            if(e % x != 0 && w % x != 0){
                t = 0;
                break;
            }
        }
        if(t) {
            cout << x << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
