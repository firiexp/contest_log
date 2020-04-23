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
    int d;
    cin >> d;
    string s, a;
    for (int i = 0; i < 30; ++i) {
        a += 'x';
    }
    cin >> s;
    s = a+s;
    {
        string t;
        cin >> t;
        s += t;
        for (int i = 0; i < 30; ++i) {
            s += 'x';
        }
    }
    int ans = 0;
    for (int i = 0; i < 74; ++i) {
        string t = s;
        for (int j = 0; i+j < 74 && j < d; ++j) {
            if(t[i+j] == 'o') break;
            t[i+j] = 'o';
        }
        int cnt = 0;
        for (int j = 0; j < 74; ++j) {
            if(t[j] == 'o') cnt++;
            else ans = max(ans, cnt), cnt = 0;
        }
    }
    cout << ans << "\n";
    return 0;
}
