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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    auto ans1 = v;
    vector<vector<vector<int>>> u(n, vector<vector<int>> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
            u[i][(v[i][j]-1)/m].emplace_back(v[i][j]);
        }
    }
    int curr = 0;
    for (int i = 0; i < n; ++i) { // No.i
        vector<int> cnt(m);
        int cur = 0;
        int X = curr; // 列
        for (int j = 0; j < m; ++j) {  // j個目
            while(u[X][i].empty()) X = (X+1)%n;
            int y = u[X][i].back(); u[X][i].pop_back();
            for (int k = 0; k < m; ++k) { // どこに置くか
                if(!ans1[X][(cur+k)%m] && !cnt[(cur+k)%m]){
                    cnt[(cur+k)%m] = 1;
                    ans1[X][(cur+k)%m] = y;
                    cur = (cur+k)%m;
                    break;
                }

            }
        }
        curr = X;
    }
    

    for (int i = 0; i < m; ++i) {
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            a[j] = ans1[j][i];
        }
        sort(a.begin(),a.end());
        for (int j = 0; j < n; ++j) {
            ans1[j][i] = a[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans1[i][j] << " ";
        }
        puts("");
    }

    return 0;
}