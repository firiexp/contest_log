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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

template<class T, bool get_max>
class CHT {
    using P = pair<T, T>;
    deque<P> lines;
public:
    CHT() = default;
    int sgn(T x) { return x == 0 ? 0 : (x > 0 ? 1 : -1); }
    bool check(P l1, P l2, P l3){
        if(l1.second == l2.second || l2.second == l3.second){
            return sgn(l1.first - l2.first)*sgn(l2.second - l3.second)
                >= sgn(l2.first - l3.first)*sgn(l1.second - l2.second);
        }else {
            return (l1.first - l2.first)*sgn(l2.second - l3.second)/ static_cast<long double>(abs(l1.second - l2.second))
                   >= (l2.first - l3.first)*sgn(l1.second - l2.second)/ static_cast<long double>(abs(l2.second - l3.second));
        }
    }

    void add_line(T a, T b) { // add ax + b
        if(get_max) a = -a, b = -b;
        P L(a, b);
        if(lines.empty()){
            lines.emplace_back(L);
            return;
        }
        if(lines.front().first <= a){
            if(lines.front().first == a){
                if(lines.front().second <= b) return;
                else lines.pop_front();
            }
            while(lines.size() >= 2 && check(L, lines.front(), lines[1])) lines.pop_front();
            lines.emplace_front(L);
        }else {
            if(lines.back().first == a){
                if(lines.back().second <= b) return;
                else lines.pop_back();
            }
            while(lines.size() >= 2 && check(lines[lines.size()-2], lines.back(), L)) lines.pop_back();
            lines.emplace_back(L);
        }
    }

    T val(const P &L, const T &x) { return L.first * x + L.second; }
    T query(T x){
        int l = -1, r = lines.size() - 1;
        while(r - l > 1){
            int mid = (l+r) >> 1;
            if(val(lines[mid], x) >= val(lines[mid+1], x)) l = mid;
            else r = mid;
        }
        return get_max ? -val(lines[r], x) : val(lines[r], x);
    }

    T query_increase(T x){
        while(lines.size() >= 2 && val(lines.front(), x) >= val(lines[1], x)) lines.pop_front();
        return get_max ? -val(lines.front(), x) : val(lines.front(), x);
    }

    T query_decrease(T x){
        while(lines.size() >= 2 && val(lines.back(), x) >= val(lines[lines.size() - 2], x)) lines.pop_back();
        return get_max ? -val(lines.back(), x) : val(lines.back(), x);
    }
};

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    vector<ll> S(n+1);
    for (int i = 0; i < n; ++i) {
        S[i+1] = S[i] + v[i];
    }
    auto dp = make_v(n+1, n+1, INF<ll>);
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
        dp[i][i] = S[i]*S[i];
    }
    for (int len = 1; len <= n; ++len) { // len = i-j;
        CHT<ll, false> cht;
        for (int j = 1; j + len <= n; ++j) {
            int i = j + len;
            cht.add_line(-2*S[i-1], dp[i-2][j-1]+S[i-1]*S[i-1]);
            dp[i][j] = min(dp[i-1][j], S[i]*S[i] + cht.query_increase(S[i]));
        }
    }
    for (int i = 1; i <= n; ++i) {
        ll ans = INF<ll>;
        for (int j = 0; j <= n; ++j) {
            ans = min(ans, dp[j][i]);
        }
        cout << ans << "\n";
    }
    return 0;
}