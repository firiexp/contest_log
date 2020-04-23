#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

vector<vector<int>> rotate(vector<vector<int>> x){
    int h = x.size(); int w = x[0].size();
    vector<vector<int>> v(w, vector<int>(h, 0));
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            v[i][j] = x[h-j-1][i];
        }
    }
    return v;
}


int main() {
    int r, k, h, w;
    cin >> r >> k >> h >> w;
    vector<vector<int>> v(h, vector<int>(w, 0));
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            v[i][j] = s[j] == '#';
        }
    }
    for (int i = 0; i < r/90; ++i) {
        v = rotate(v);
    }
    h = v.size(), w = v[0].size();
    for (int i = 0; i < h; ++i) {
        for (int m = 0; m < k; ++m) {
            for (int j = 0; j < w; ++j) {
                for (int l = 0; l < k; ++l) {
                    cout << (v[i][j] ? '#' : '.');
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
