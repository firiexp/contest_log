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

int main() {
    int q;
    cin >> q;
    array<map<string, int>, 20> v;
    for (int i = 0; i < q; ++i) {
        int p;
        cin >> p;
        if(p == 0){
            int n, m;
            cin >> n >> m;
            n--;
            for (int j = 0; j < m; ++j) {
                string s;
                cin >> s;
                v[n][s]++;
            }
        }else if (p == 1){
            string s;
            cin >> s;
            int ans = -1;
            for (int j = 0; j < 20; ++j) {
                if(ans == -1 && v[j].count(s)){
                    ans = j+1;
                    v[j][s]--;
                    if(v[j][s] == 0) v[j].erase(s);
                }
            }
            cout << ans << "\n";
        }else {
            int x;
            cin >> x;
            x--;
            v[x].clear();
        }
    }
    return 0;
}
