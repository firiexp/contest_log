#include <iostream>
#include <algorithm>
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
    int n, m;
    while(cin >> n >> m, n){
        vector<char> v(n+2);
        for (int _ = 0; _ < m; ++_) {
            char c;
            cin >> c;
            if(c == 'A'){
                for (int j = 1; j <= n; ++j) {
                    if(!v[j]){
                        v[j] = c;
                        break;
                    }
                }
            }else if(c == 'B'){
                int ok = 0;
                for (int j = n; j >= 1; --j) {
                    if(!v[j] && v[j-1] != 'A' && v[j+1] != 'A'){
                        v[j] = c;
                        ok = 1;
                        break;
                    }
                }
                if(!ok){
                    for (int j = 1; j <= n; ++j) {
                        if(!v[j]){
                            v[j] = c;
                            break;
                        }
                    }
                }
            }else if(c == 'C'){
                int ok = 0;
                for (int j = 1; j <= n; ++j) {
                    if(!v[j]) continue;;
                    if(j != n && !v[j+1]){
                        v[j+1] = c;
                        ok = 1;
                        break;
                    }
                    if(j != 1 && !v[j-1]){
                        v[j-1] = c;
                        ok = 1;
                        break;
                    }
                }
                if(!ok){
                    v[(n+2)/2] = c;
                }
            }else if(c == 'D'){
                int cur = 1, dist = 0;
                for (int j = 1; j <= n; ++j) {
                    if(v[j]) continue;
                    int d = INF<int>;
                    for (int k = 1; k <= n; ++k) {
                        if(v[k]){
                            d = min(d, abs(j-k));
                        }
                    }
                    if(d > dist){
                        dist = d;
                        cur = j;
                    }
                }
                v[cur] = c;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if(v[i]) cout << v[i];
            else cout << "#";
        }
        puts("");
    }
    return 0;
}