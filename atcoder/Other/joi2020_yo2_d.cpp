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

int main() {
    int m, r;
    cin >> m >> r;
    vector<vector<int>> d(10, vector<int>(m, INF<int>));
    vector<vector<int>> v{{1}, {0, 2, 4}, {1, 3, 5}, {2, 6}, {1, 5, 7}, {2, 4, 6, 8}, {3, 5, 9}, {4, 8}, {5, 7, 9}, {6, 8}};
    d[0][0] = 0;
    queue<pair<int, int>> Q;
    Q.emplace(0, 0);
    while(!Q.empty()){
        int a, b; tie(a, b) = Q.front(); Q.pop();
        if(b == r) {
            cout << d[a][b] << "\n";
            return 0;
        }
        if(d[a][(b*10+a)%m] > d[a][b]+1){
            d[a][(b*10+a)%m] =  d[a][b]+1;
            Q.emplace(a,(b*10+a)%m);
        }
        for (auto &&i : v[a]) {
            if(d[i][b] > d[a][b]+1){
                d[i][b] = d[a][b]+1;
                Q.emplace(i, b);
            }
        }
    }
    return 1;
}