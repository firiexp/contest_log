#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, m;
    while(cin >> n, n){
        cin >> m;
        int ans = 0, cnt = 0;
        string s;
        cin >> s;
        for (int i = 0; i < m; ++i) {
            char target = (cnt%2 ? 'O' : 'I');
            if(s[i] == target) cnt++;
            else {
                ans += max(0, (cnt-1)/2-n+1);
                cnt = 0;
                target = (cnt%2 ? 'O' : 'I');
                if(s[i] == target) cnt++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
