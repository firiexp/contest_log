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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(h+2, vector<int>(w+2, 0));
    vector<int> a(h), b(w);
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i+1][j+1] = (s[j] == '*');
            a[i] += v[i+1][j+1];
            b[j] += v[i+1][j+1];
        }
    }
    int x = 0, y = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(v[i][j+1] + v[i+1][j] + v[i+2][j+1] + v[i+1][j+2] == 4){
                y = i+1, x = j+1;
            }
        }
    }
    if(!v[y][x]){
        puts("NO");
        return 0;
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if((y != i+1 && x != j+1) && v[i+1][j+1]) {
                puts("NO");
                return 0;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i <= h; ++i) {
        if(v[i][x] != v[i+1][x]) {
            cnt++;
        }
    }
    if(cnt != 2){
        puts("NO");
        return 0;
    }
    cnt = 0;
    for (int i = 0; i <= w; ++i) {
        if(v[y][i] != v[y][i+1]) {
            cnt++;
        }
    }
    if(cnt != 2){
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}