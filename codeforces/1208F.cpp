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
using ar = array<int, 3>;
int main() {
    int n, w;
    cin >> n >> w;
    vector<array<int, 3>> v;
    for (int i = 0; i < n; ++i) {
        int l; scanf("%d", &l);
        for (int j = 0; j < l; ++j) {
            int x;
            scanf("%d", &x);
            v.emplace_back(ar{j, x, 0});
            v.emplace_back(ar{j+w-l+1, x, 1});
        }
    }
    v.emplace_back(ar{INF<int>, 0, 0});
    sort(v.begin(),v.end());
    int cur = 0;
    ll ans = 0;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        while(v[cur][0] == i){
            if(v[cur][2] == 0){
                s.
            }
            cur++;
        }
        if(i) printf(" ");
        printf("%lld", ans);
    }
    return 0;
}