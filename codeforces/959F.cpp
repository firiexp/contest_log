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
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<pair<pair<int, int>, int>> query(q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &query[i].first.first, &query[i].first.second);
        query[i].second = i;
    }
    vector<mint> pow2(n+1);
    pow2[0] = 1;
    for (int i = 0; i < n; ++i) {
        pow2[i+1] = pow2[i]+pow2[i];
    }
    vector<int> ans(q);
    sort(query.begin(),query.end());
    vector<int> base, base2;
    int cur = 0;
    for (int i = 0; i < query.size(); ++i) {
        while(cur < query[i].first.first){
            base.emplace_back(v[cur]);
            int N = base.size(), m = 20;
            int cnt = 0;
            for (int j = 0; j < m && cnt != N; ++j) {
                int p = cnt;
                for (int k = cnt; k < N; ++k) {
                    if(base[k] & (1 << j)){
                        p = k;
                        break;
                    }
                }
                if((base[p] & (1 << j)) == 0) continue;
                swap(base[cnt], base[p]);
                for (int k = 0; k < N; ++k) {
                    if(cnt == k) continue;
                    if(base[k] & (1 << j)) base[k] ^= base[cnt];
                }
                cnt++;
            }
            if(base.size() != cnt) base.pop_back();
            cur++;
        }
        base2 = base;
        base2.emplace_back(query[i].first.second);
        int N = base2.size(), m = 20;
        int cnt = 0;
        for (int j = 0; j < m && cnt != N; ++j) {
            int p = cnt;
            for (int k = cnt; k < N; ++k) {
                if(base2[k] & (1 << j)){
                    p = k;
                    break;
                }
            }
            if((base2[p] & (1 << j)) == 0) continue;
            swap(base2[cnt], base2[p]);
            for (int k = 0; k < N; ++k) {
                if(cnt == k) continue;
                if(base2[k] & (1 << j)) base2[k] ^= base2[cnt];
            }
            cnt++;
        }
        if(base.size() != cnt) ans[query[i].second] = 0;
        else ans[query[i].second] = pow2[cur-base.size()].val;
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}