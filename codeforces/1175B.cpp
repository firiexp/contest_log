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
    int l;
    cin >> l;
    ll ans = 0, MAX = UINT32_MAX, x = 1;
    stack<int> t;
    int dep = 0;
    for (int i = 0; i < l; ++i) {
        string s;
        cin >> s;
        if(s == "add"){
            ans += x;
            if(ans > MAX) {
                puts("OVERFLOW!!!");
                return 0;
            }
        }else if(s == "for"){
            ll y;
            scanf("%lli", &y);
            dep++;
            if(MAX*101 >= x && dep-1 == t.size()){
                x *= y;
                t.emplace(y);
            }

        }else if(s == "end"){
            dep--;
            while (dep < t.size()) x /= t.top(), t.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}