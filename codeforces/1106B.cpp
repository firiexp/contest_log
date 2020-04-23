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

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), C(n);
    for (auto &&i : A) scanf("%d", &i);
    for (auto &&j : C) scanf("%d", &j);
    ll sum = 0;
    using P = pair<int, int>;
    set<P> s;
    for (int i = 0; i < n; ++i) {
        sum += A[i];
        s.emplace(C[i], i);
    }
    for (int i = 0; i < m; ++i) {
        int t, d;
        scanf("%d %d", &t, &d);
        ll ans = 0;
        t--;
        if(A[t]){
            ll val = min(A[t], d);
            ans += C[t]*val;
            s.erase(make_pair(C[t], t));
            A[t] -= val;
            d -= val;
            if(A[t]){
                s.emplace(make_pair(C[t], t));
            }
        }
        while(d && !s.empty()){
            auto p = *s.begin(); s.erase(s.begin());
            ll val = min(A[p.second], d);
            A[p.second] -= val;
            d -= val;
            ans += val*p.first;
            if(A[p.second]){
                s.emplace(make_pair(C[p.second], p.second));
            }
        }
        if(!d) printf("%lld\n", ans);
        else puts("0");
    }
    return 0;
}