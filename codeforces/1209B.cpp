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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i], &b[i]);
    }
    vector<int> v(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        v[i] = s[i] - '0';
        cnt += v[i];
    }
    int ans = cnt;
    for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i >= b[j] && (i-b[j])%a[j] == 0) {
                v[j] ^= 1;
                if(v[j]) cnt++;
                else cnt--;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}