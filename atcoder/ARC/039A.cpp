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
    string s;
    cin >> s;
    int a = s[0]-'0', b = s[1]-'0', c =s[2]-'0';
    cin >> s;
    int d = s[0]-'0', e = s[1]-'0', f =s[2]-'0';
    int ans = max({9*100+b*10+c*1-d*100-e*10-f,
                   a*100+9*10+c*1-d*100-e*10-f,
                   a*100+b*10+9*1-d*100-e*10-f,
                   a*100+b*10+c*1-1*100-e*10-f,
                   a*100+b*10+c*1-d*100-0*10-f,
                   a*100+b*10+c*1-d*100-e*10-0});
    cout << ans << "\n";
    return 0;
}
