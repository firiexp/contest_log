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


int main() {
    auto v = make_v(50, 50, 0);
    int a = 25, b = 25, dir = 0;
    array<int, 4> dy{-1, 0, 1, 0}, dx{0, 1, 0, -1};
    v[a][b] = 2;
    auto dfs = [&](auto &&f) -> int {
        for (int i = 0; i < 4; ++i) {
            string s;
            getline(cin, s);
            if(s == "Merry Christmas!") return 0;
            if(s == "20151224") return 1;
            int val = stoi(s);
            if(!v[a+dy[dir]][b+dx[dir]]){
                v[a+dy[dir]][b+dx[dir]] = val+1;
                if(val){
                    cout << "F" << endl;
                    a += dy[dir]; b += dx[dir];
                    int ret = f(f);
                    if(ret >= 0) return ret;
                    cout << "B" << endl;
                    a -= dy[dir]; b -= dx[dir];
                    getline(cin, s);
                    if(s == "Merry Christmas!") return 0;
                    if(s == "20151224") return 1;
                }
            }
            cout << "R" << endl;
            dir = (dir+1)%4;
        }
        string s;
        getline(cin, s);
        if(s == "Merry Christmas!") return 0;
        if(s == "20151224") return 1;
        return -1;
    };
    int ret = dfs(dfs);
    if(ret){
        while(true){
            cout << "F" << endl;
            string s;
            getline(cin, s);
            if(s == "Merry Christmas!") break;
        }
    }
    return 0;
}