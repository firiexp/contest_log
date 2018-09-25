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
    auto t = s.length()+1;
    int ans = INF<int>;
    for (char i = 'a'; i <= 'z'; ++i) {
        string ss = "?" + s;
        if(s.find(i) == string::npos) continue;
        int a = 0;
        while(true) {
            bool flag = true;
            for (int j = 0; j < t; ++j) {
                if (ss[j] != i && ss[j] != '?') flag = false;
            }
            if (flag) {
                break;
            }else {
                for (int j = static_cast<int>(t - 2); j >= 0; --j) {
                    if(ss[j] == '?') ss[j+1] = ss[j];
                    if(ss[j] == i) ss[j+1] = ss[j];
                }
                a++;
            }
        }
        ans = min(a, ans);
    }
    cout << ans << "\n";
    return 0;
}
