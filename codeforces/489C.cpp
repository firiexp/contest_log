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
    int m, s;
    cin >> m >> s;
    if((m != 1 && s == 0) || s > 9*m){
        puts("-1 -1");
        return 0;
    }else if(m == 1){
        cout << s << " " << s << "\n";
        return 0;
    }
    string mx(m, '0');
    mx[0] = '1';
    string mn = mx;
    int cur = 0;
    for (int i = 0; i < s-1; ++i) {
        if(mx[cur] == '9') cur++;
        mx[cur]++;
    }
    cur = m-1;
    for (int i = 0; i < s-1; ++i) {
        if(mn[cur] == '9') cur--;
        mn[cur]++;
    }
    cout << mn << " " << mx << "\n";
    return 0;
}
