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
    int n;
    cin >> n;
    vector<int> v{3, 5, 7};
    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        vector<int> u;
        for (auto &&j : v) {
            u.emplace_back(j*10+3);
            u.emplace_back(j*10+5);
            u.emplace_back(j*10+7);
        }
        for (auto &&j : u) {
            int a = 0, b = 0, c = 0;
            int x = j;
            while (x){
                if(x % 10 == 3) a++;
                if(x % 10 == 5) b++;
                if(x % 10 == 7) c++;
                x /= 10;
            }
            if((a&&b&&c) && (j <= n)) ans++;
        }
        v = u;
    }
    cout << ans << "\n";
    return 0;
}
