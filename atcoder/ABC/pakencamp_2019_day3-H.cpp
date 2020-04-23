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

#include <chrono>
class xor_shift {
    uint32_t x, y, z, w;
public:
    xor_shift() : x(static_cast<uint32_t>((chrono::system_clock::now().time_since_epoch().count())&((1LL << 32)-1))),
                  y(1068246329), z(321908594), w(1234567890) {};

    uint32_t urand(){
        uint32_t t;
        t = x ^ (x << 11);
        x = y; y = z; z = w;
        w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
        return w;
    };

    int rand(int n){
        if(n < 0) return -rand(-n);
        uint32_t t = numeric_limits<uint32_t>::max()/(n+1)*(n+1);
        uint32_t e = urand();
        while(e >= t) e = urand();
        return static_cast<int>(e%(n+1));
    }

    int rand(int a, int b){
        if(a > b) swap(a, b);
        return a+rand(b-a);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    xor_shift rd;
    vector<string> v(n);
    vector<pair<int, int>> ps, es;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        for (int j = 0; j < n; ++j) {
            if(v[i][j] == 'X'){
                ps.emplace_back(i, j);
            }else if(v[i][j] == 'Q'){
                es.emplace_back(i, j);
            }
        }
    }
    vector<vector<pair<int, int>>> vs;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int a = es[j].first - ps[i].first;
            int b = es[j].second - ps[i].second;
            int c = __gcd(abs(a), abs(b));
            if(c == max(abs(a), abs(b))){
                a /= c; b /= c;
                int xx = ps[i].first + a;
                int yy = ps[i].second + b;
                vs.emplace_back();
                while(xx != es[j].first || yy != es[j].second){
                    if(v[xx][yy] == '.') vs.back().emplace_back(xx, yy);
                    xx += a; yy += b;
                }
            }
        }
    }
    sort(vs.begin(),vs.end(), [&](vector<pair<int, int>> &a, vector<pair<int, int>> &b){ return a.size() < b.size(); });
    for (auto &&i : vs) {
        int cnt = 0;
        for (auto &&j : i) {
            cnt += (v[j.first][j.second] == '#');
        }
        if(cnt == 0){
            int val = rd.rand((int)i.size()-1);
            v[i[val].first][i[val].second] = '#';
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << v[i] << "\n";
    }
    return 0;
}