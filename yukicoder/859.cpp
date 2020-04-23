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
    vector<int> vs(3);
    int a, b; char as, bs;
    cin >> vs[0] >> vs[1] >> vs[2] >> as >> a >> bs >> b;
    vector<vector<ll>> G(12, vector<ll>(12, INF<ll>));
    for (int i = 0; i < 12; ++i) {
        G[i][i] = 0;
    }
    auto add = [&](int p, int q, int c){
        G[p][q] = G[q][p] = c;
    };
    for (int i = 0; i < 3; ++i) {
        vector<int> v{1, a, b, vs[i]};
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if(j == k) continue;
                add(i*4+j, i*4+k, abs(v[j]-v[k]));
            }
        }
    }
    add(0, 4, 1); add(0, 8, 1);
    add(4, 8, 1);
    add(3, 7, 1); add(3, 11, 1);
    add(7, 11, 1);
    for (int k = 0; k < 12; ++k) {
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 12; ++j) {
                G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }
    cout << G[(as-'A')*4+1][(bs-'A')*4+2] << "\n";
    return 0;
}