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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int a = 0, b = 0;
    vector<pair<char,int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf(" %c %d", &v[i].first, &v[i].second);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        int c, d; tie(c, d) = v[i];
        if(c == 'R'){
            if(d == b) {
                a--;
                if(a < 0) a += w;
            }
        }else {
            if(d == a) {
                b--;
                if(b < 0) b += h;
            }
        }
    }
    puts((a+b)%2 ?  "black": "white");
    return 0;
}
