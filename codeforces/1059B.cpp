#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;


int dx[8] = {0, 0, 0, 1, 1, 2, 2, 2}, dy[8] = {0, 1, 2, 0, 2, 0, 1, 2};



int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<vector<int>> v2(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if(s[j] == '#') v[i][j] = 1;
        }
    }
    for (int i = 0; i < n-2; ++i) {
        for (int j = 0; j < n-2; ++j) {
            if(v[i][j] != v2[i][j]){
                for (int k = 0; k < 8; ++k) {
                    v2[i+dx[k]][j+dy[k]] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(v[i][j] != v2[i][j]){
                cout << "NO" << "\n";
                return 0;
            }
        }
    }
    cout << "YES" << "\n";
    return 0;
}
