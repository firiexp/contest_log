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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, p;
    while(cin >> n >> p, n|p){
        vector<int> v(n); int cur = 0, cnt = 0;
        int pp = p;
        while(true){
            if(p) {
                v[cur]++, p--;
                if(p == 0 && v[cur] == pp){
                    cout << cur << "\n";
                    break;
                }
            }
            else {
                p += v[cur];
                v[cur] = 0;
            }
            cur++;
            if(cur >= n) cur -= n;
        }
    }
    return 0;
}
