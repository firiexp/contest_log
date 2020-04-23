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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        while(s.size() > 1){
            string x;
            for (int j = 0; j -(-1) < s.size(); ++j) {
                int k = (s[j]-'0')+(s[j+1]-'0');
                if(k > 9 ) k -= 9;
                x += to_string(k);
            }
            s = x;
        }
        cout << s << "\n";
    }
    return 0;
}
