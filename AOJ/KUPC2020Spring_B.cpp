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

struct dice {
    int u, d, l, r, f, b;

    void spinl(){ // f -> l
        int tmp = f; f = r; r = b; b = l; l = tmp;
    }
    void spinr(){
        for (int i = 0; i < 3; ++i) spinl();
    }

    void gof(){
        int tmp = f; f = u; u = b; b = d; d = tmp;
    }

    void gob(){
        for (int i = 0; i < 3; ++i) gof();
    }

    void gor(){
        int tmp = u; u = l; l = d; d = r; r = tmp;
    }

    void gol(){
        for (int i = 0; i < 3; ++i) gor();
    }

    dice(int a, int x) {
        u = 1, d = 6, f = 2, b = 5, l = 4, r = 3;
        if(a == 2) gob();
        else if(a == 3) gol();
        else if(a == 4) gor();
        else if(a == 5) gof();
        else if(a == 6) gof(), gof();
        while(f != x) spinl();
    }
    dice(){
        u = 0, d = 0, f = 0, b = 0, l = 0, r = 0;
    }
};

int main() {
    dice D(1, 2);
    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(h+2, vector<int>(w+2, 0));

    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if(s[j] != '#') v[i+1][j+1] = s[j] - '0';
        }
    }
    vector<vector<dice>> a(h+2, vector<dice>(w+2));
    a[1][1] = D;
    queue<pair<int, int>> Q;
    Q.emplace(1, 1);
    while(!Q.empty()){
        int y, x; tie(y, x) = Q.front(); Q.pop();
        dice d = a[y][x];
        if(v[y-1][x] && a[y-1][x].r == 0){
            d.gob();
            if(d.d == v[y-1][x]){
                Q.emplace(y-1, x);
                a[y-1][x] = d;
            }
            d.gof();
        }
        if(v[y+1][x] && a[y+1][x].r == 0){
            d.gof();
            if(d.d == v[y+1][x]){
                Q.emplace(y+1, x);
                a[y+1][x] = d;
            }
            d.gob();
        }
        if(v[y][x-1] && a[y][x-1].r == 0){
            d.gol();
            if(d.d == v[y][x-1]){
                Q.emplace(y, x-1);
                a[y][x-1] = d;
            }
            d.gor();
        }
        if(v[y][x+1] && a[y][x+1].r == 0){
            d.gor();
            if(d.d == v[y][x+1]){
                Q.emplace(y, x+1);
                a[y][x+1] = d;
            }
            d.gol();
        }
    }
    if(a[h][w].d){
        puts("YES");
    }else {
        puts("NO");
    }
    return 0;
}