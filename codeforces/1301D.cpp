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


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    if(4*n*m-2*n-2*m < k) {
        puts("NO");
        return 0;
    }
    puts("YES");
    vector<pair<int, string>> ret;
    auto add = [&](int x, string s){
        if(x <= 0) return;
        else ret.emplace_back(x, s);
    };
    int cur = 0, cnt = 0;
    while(k){
        if(cur == 0){
            add(min(k, m-1), (cnt&1 ? "L" : "R"));
            k -= min(k, m-1);
            if(cnt == n-1){
                cur++;
            } else if(k){
                k--;
                add(1, "D");
            }
            cnt++;
        }else if(cur == 1){
            add(min(k, m-1), (n & 1 ? "L" : "R"));
            k -= min(k, m-1);
            if(k){
                k--;
                add(1, "U");
            }
            cur++;
        }else {
            add(min(m-1, k/3), (cnt&1 ? "RDU" : "LDU"));
            if(min(m-1, k/3) == m-1){
                k -= (m-1)*3;
            }else {
                k -= k/3*3;
                if(k){
                    add(1, string(cnt&1 ? "RDU" : "LDU").substr(0, k));
                    k = 0;
                }
            }
            if(k){
                add(1, "U");
                k--;
            }
            cnt--;
        }
    }
    cout << ret.size() << "\n";
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i].first << " " << ret[i].second << "\n";
    }
    return 0;
}