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
int h, w, n;
array<int, 4> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool solve(vector<vector<char>> grid){
    int ok = 1;
    for (int i = 1; i <= h; ++i) {
        stable_sort(grid[i].begin()+1, grid[i].end()-1, [](char a, char b){
            return ((a == '.') > (b == '.'));
        });
    }

    while(true){
        ok = 0;
        vector<vector<bool>> kie(h+2, vector<bool>(w+2, false));
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                if(!isalpha(grid[i][j])) continue;
                for (int k = 0; k < 4; ++k) {
                    int y = i, x = j;
                    while(grid[y+dy[k]][x+dx[k]] == grid[i][j]) y += dy[k], x += dx[k];
                    if(abs(y-i)+abs(x-j)+1 >= n){
                        for (int p = 0; p <= abs(y-i)+abs(x-j); ++p) {
                            kie[i+dy[k]*p][j+dx[k]*p] = true;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                if(kie[i][j]) ok = 1, grid[i][j] = '.';
            }
        }
        if(!ok) break;
        for (int i = 1; i <= h; ++i) {
            stable_sort(grid[i].begin()+1, grid[i].end()-1, [](char a, char b){
                return ((a == '.') > (b == '.'));
            });
        }

    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(grid[i][j] != '.') return false;
        }
    }
    return true;
}

int main() {

    cin >> h >> w >> n;
    swap(h, w);
    vector<vector<char>> v(h+2, vector<char> (w+2, 0));
    for (int i = 0; i < w; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < h; ++j) {
            v[j+1][i+1] = s[j];
        }
    }
    for (int i = 1; i < h; ++i) {
        for (int j = 1; j <= w; ++j) {
            swap(v[i][j], v[i+1][j]);
            if(solve(v)){
                puts("YES");
                return 0;
            }
            swap(v[i][j], v[i+1][j]);
        }
    }
    cout << "NO" << "\n";
    return 0;
}