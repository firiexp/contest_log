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
    int n, m, q;
    while(cin >> n >> m >> q, n){
        vector<bitset<50>> v(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                v[j].set(i);
            }
        }
        bitset<50> b;
        for (int i = 0; i < q; ++i) {
            string s, t;
            cin >> s >> t;
            for (int j = 0; j < n; ++j) {
                if(s[j] == '1') b[j].flip();
            }

            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    if(b[j] && t[k] == '0') v[k][j] = false;
                    if(!b[j] && t[k] == '1') v[k][j] = false;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            if(v[i].count() == 1){
                for (int j = 0; j < n; ++j) {
                    if(v[i][j]) {
                        if(j >= 10) printf("%c", j-10+'A');
                        else printf("%d", j);
                        break;
                    }
                }
            }else printf("?");
        }
        puts("");
    }
    return 0;
}