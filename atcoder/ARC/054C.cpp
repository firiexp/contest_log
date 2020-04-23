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
    int n;
    cin >> n;
    vector<bitset<200>> v(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if(s[j] == '1') v[i].set(j);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n && cnt != n; ++i) {
        int p = cnt;
        for (int j = cnt; j < n; ++j) {
            if(v[j][i]){
                p = j;
                break;
            }
        }
        if(!v[p][i]) continue;
        swap(v[cnt], v[p]);
        for (int j = 0; j < n; ++j) {
            if(cnt == j) continue;
            if(v[j][i]) v[j] ^= v[cnt];
        }
        cnt++;
    }
    puts(cnt == n ? "Odd" : "Even");
    return 0;
}
