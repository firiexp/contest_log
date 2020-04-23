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

template<class T, class F>
class sliding_window {
    vector<T> v;
    deque<T> Q;
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
    T get_index()  {
        if(l == r) return 0;
        return Q.front();
    }
    T value()  {
        if(l == r) return 0;
        return v[Q.front()];
    }
};


template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    auto f = [](ll a, ll b){ return a > b; };
    vector<ll> dp(v);
    sliding_window<ll, decltype(f)> g(dp, f);
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[j] = 0;
        }
        for (int j = i; j < n; ++j) {
            while(j > g.r) g.slideR();
            while(j-m > g.l) g.slideL();
            dp[j] = g.value() + v[j]*(i+1);
        }
        g.set(dp);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}
