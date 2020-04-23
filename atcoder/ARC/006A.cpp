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
    vector<int> v(6), v2(6);
    for (auto &&i : v) cin >> i;
    int b;
    cin >> b;
    for (auto &&i : v2) cin >> i;
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    int k = 0, x = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if(v[i] == v2[j]) k++;
        }
        if(v2[i] == b) x++;
    }
    int ans = 0;
    if(k == 6) ans = 1;
    else if(k == 5){
        if(x) ans = 2;
        else ans = 3;
    }else if(k == 4) ans = 4;
    if(k == 3) ans = 5;
    cout << ans << "\n";
    return 0;
}
