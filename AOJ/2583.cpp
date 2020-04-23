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
    int n;
    while(cin >> n ,n){
        vector<vector<char>> v(n+5, vector<char>(2000, '?'));
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int ok = 0;
            for (int j = (int)s.size()-1; j >= 0; --j) {
                v[i+1][j] = s[j];
                if(v[i+1][j] == '.' && !ok){
                    ok = 1;
                    v[i+1][j] = '+';
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2000; ++j) {
                if(v[i][j] == '+'){
                    int cur = i+1;
                    while(v[cur][j] == '.') cur++;
                    if(v[cur][j] == '+'){
                        for (int k = i+1; k < cur; ++k) {
                            v[k][j] = '|';
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            int cur = 0;
            while(v[i][cur] != '?') {
                if(v[i][cur] == '.') printf(" ");
                else printf("%c", v[i][cur]);
                cur++;
            }
            puts("");
        }
        
    }
    return 0;
}