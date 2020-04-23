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
    int t, p, r;
    while(cin >> t >> p >> r, t){
        vector<array<int, 3>> team(t);
        for (int i = 0; i < t; ++i) {
            team[i][2] = i;
        }
        vector<vector<int>> wa(t, vector<int>(p));
        while(r--){
            int a, b, c; string s;
            cin >> a >> b >> c >> s;
            a--; b--;
            if(s == "CORRECT"){
                team[a][0]--; team[a][1] += c+wa[a][b]*1200;
            }else {
                wa[a][b]++;
            }
        }
        sort(team.begin(),team.end());
        for (int i = 0; i < t; ++i) {
            printf("%d %d %d\n", team[i][2]+1, -team[i][0], team[i][1]);
        }
    }
    return 0;
}