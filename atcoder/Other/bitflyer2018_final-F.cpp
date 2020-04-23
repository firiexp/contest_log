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

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> v(h, vector<int> (w, 0));
    vector<vector<int>> ok(h+1, vector<int> (w+1, 0));
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i][j] = (s[j] == '#');
        }
    }
    using P = pair<int, int>;
    set<P> s;
    for (int i = 0; i < h-1; ++i) {
        for (int j = 0; j < w-1; ++j) {
            ok[i+1][j+1] = 1;
            int x = v[i][j]+v[i+1][j]+v[i][j+1]+v[i+1][j+1];
            if(x&1) s.emplace(i, j);
        }
    }
    auto f = [&s](){
        if(s.empty()) return true;
        if(s.size() == 1) return true;
        if(s.size() == 2){
            P a = *s.begin(), b = *(++s.begin());
            return a.first == b.first || a.second == b.second;
        }
        if(s.size() == 4){
            map<int, int> a;
            for (auto &&i : s) {
                a[i.first+(1<<15)]++; a[i.second]++;
            }
            for (auto &&i : a) {
                if(i.second != 2) return false;
            }
            return true;
        }
        return false;
    };
    puts(f() ? "Yes" : "No");
    for (int i = 0; i < q-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        for (int j = -1; j < 1; ++j) {
            for (int k = -1; k < 1; ++k) {
                if(!ok[a+j][b+k]) continue;
                P x(a+j-1, b+k-1);
                if(s.count(x)) {
                    s.erase(x);
                }else {
                    s.insert(x);
                }
            }
        }
        puts(f() ? "Yes" : "No");
    }
    return 0;
}