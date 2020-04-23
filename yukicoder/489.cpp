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

template<class T, class F>
class sliding_window {
    vector<T> v;
    deque<int> Q;
    F f;
public:
    int l, r;
    explicit sliding_window(vector<T> &v, F f) : v(v), f(f), l(0), r(0) {};
    void set(vector<T> &u){
        v = u;
        Q.clear();
        l = 0; r = 0;
    }
    void reset(){
        Q.clear();
        l = 0, r = 0;
    }
    void slideL(){
        if(Q.front() == l++) Q.pop_front();
    }
    void slideR(){
        while(!Q.empty() && !f(v[Q.back()], v[r])) Q.pop_back();
        Q.push_back(r++);
    }
    int get_index()  {
        if(l == r) return 0;
        return Q.front();
    }
    T value()  {
        if(l == r) return T{};
        return v[Q.front()];
    }
};

int main() {
    ll n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    auto f = [&](pair<int, int> x, pair<int, int> y){
        return x < y;
    };
    sliding_window<pair<int, int>, decltype(f)> a(v, f);
    ll cur1 = 0, cur2 = 0, ans = 0;
    for (int i = 1; i < n; ++i) {
        a.slideR();
        if(i > d) a.slideL();
        ll val = k*(v[i].first-a.value().first);
        if(ans < val){
            ans = val;
            cur1 = a.get_index();
            cur2 = i;
        }
    }
    if(ans){
        cout << ans << "\n";
        cout << cur1 << " " << cur2 << "\n";
    }else {
        cout << ans << "\n";
    }
    return 0;
}