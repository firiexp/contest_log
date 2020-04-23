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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s, t;
    cin >> s >> t;
    if(s.size() < t.size()) cout << t << "\n";
    else if(s.size() > t.size()) cout << s << "\n";
    else {
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == t[i]) continue;
            if(s[i] == '4' && t[i] == '7'){
                cout << s << "\n";
                return 0;
            }else if(s[i] == '7' && t[i] == '4'){
                cout << t << "\n";
                return 0;
            }else {
                cout << ((s[i] < t[i]) ? t : s) << "\n";
                return 0;
            }
        }
    }
    return 0;
}
