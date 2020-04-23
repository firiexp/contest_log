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

static const int MOD = 998244353;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<u32 M = 1000000007>
struct modint{
    u32 val;
    modint(): val(0){}
    template<typename T>
    modint(T t){t %= (T)M; if(t < 0) t += (T)M; val = t;}

    modint pow(ll k) const {
        modint res(1), x(val);
        while(k){
            if(k&1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }
    template<typename T>
    modint& operator=(T t){t %= (T)M; if(t < 0) t += (T)M; val = t; return *this;}
    modint inv() const {return pow(M-2);}
    modint& operator+=(modint a){val += a.val; if(val >= M) val -= M; return *this;}
    modint& operator-=(modint a){if(val < a.val) val += M-a.val; else val -= a.val; return *this;}
    modint& operator*=(modint a){val = (u64)val*a.val%M; return *this;}
    modint& operator/=(modint a){return (*this) *= a.inv();}
    modint operator+(modint a) const {return modint(val) +=a;}
    modint operator-(modint a) const {return modint(val) -=a;}
    modint operator*(modint a) const {return modint(val) *=a;}
    modint operator/(modint a) const {return modint(val) /=a;}
    modint operator-(){return modint(M-val);}
    bool operator==(const modint a) const {return val == a.val;}
    bool operator!=(const modint a) const {return val != a.val;}
    bool operator<(const modint a) const {return val < a.val;}
};
using mint = modint<MOD>;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> v2(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
        v2[i] = v[i].first;
    }
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    vector<int> rs(n);
    deque<tuple<int, int, mint>> Q;
    for (int i = n-1; i >= 0; --i) {
        int rr = v[i].first+v[i].second-1;
        mint val = 1;
        while(!Q.empty() && get<1>(Q.back()) <= rr){
            rr = max(rr, get<0>(Q.back()));
            val *= get<2>(Q.back());
            Q.pop_back();
        }
        rs[i] = rr;
        Q.emplace_back(rs[i], get<0>(v[i]), val+1);
    }
    mint ans = 1;
    while(!Q.empty()){
        ans *= get<2>(Q.back()); Q.pop_back();
    }
    cout << ans.val << "\n";
    return 0;
}