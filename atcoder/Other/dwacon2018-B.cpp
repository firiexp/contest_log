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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    string s;
    cin >> s;
    int p = 0, ans = 0;
    for (auto &&a : s) {
        if(a == '2') p++;
        else p--;
        if(p < 0) {
            cout << "-1\n";
            return 0;
        }
        ans = max(ans, p);
    }
    if(p != 0){
        cout << "-1\n";
    }else{
        cout << ans << "\n";
    }
    return 0;
}
