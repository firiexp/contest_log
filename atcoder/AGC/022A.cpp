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
    for(char i = 'a'; i <= 'z'; ++i){
        if(s.find(i) == string::npos){
            cout << s + i << "\n";
            return 0;
        }
    }
    for (auto i = s.length()-1; i >= 1; --i) {
        if(s[i]<s[i-1]) continue;
        else {
            for (char j = static_cast<char>(s[i - 1] + 1); j <= 'z'; ++j) {
                if(s.substr(0,i-1).find(j) == string::npos) {cout << s.substr(0,i-1)+j;
                return 0;
                }
            }
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
