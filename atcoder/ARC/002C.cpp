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
    int n;
    cin >> n;
    string s, t = "ABXY";
    cin >> s;
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    if(i == k && j == l) continue;
                    int cur = 0, p = 0;
                    while(cur+1 < n){
                        if(s[cur] == t[i] && s[cur+1] == t[j]) cur++, p++;
                        else if(s[cur] == t[k] && s[cur+1] == t[l]) cur++, p++;
                        cur++;
                    }
                    ans = max(ans, p);
                }
            }
        }
    }
    cout << n-ans << "\n";
    return 0;
}
