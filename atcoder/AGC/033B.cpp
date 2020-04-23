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
    int h, w, n;
    cin >> h >> w >> n;
    int a, b; string s, t;
    cin >> a >> b >> s >> t;
    string X = "LRUD";
    int dx[] {-1, 1, 0, 0}, dy[] {0, 0, -1, 1};
    auto in = [&](int yy, int xx){
        return 1 <= yy && yy <= h && 1 <= xx && xx <= w;
    };
    for (int i = 0; i < 4; ++i) {
        char taka = X[i], ao = X[i^1];
        int p = a, q = b;
        for (int j = 0; j < n; ++j) {
            if(s[j] == taka){
                p += dy[i], q += dx[i];
            }
            if(!in(p, q)){
                puts("NO");
                return 0;
            }
            if(t[j] == ao && in(p+dy[i^1], q+dx[i^1])){
                p += dy[i^1], q += dx[i^1];
            }
        }
    }
    puts("YES");
    return 0;
}