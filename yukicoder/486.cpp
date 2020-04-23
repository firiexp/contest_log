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
    if(s.length() <= 2){
        cout << "NA\n";
        return 0;
    }
    for (int i = 0; i < s.length()-2; ++i) {
        if(s[i] == s[i+1] && s[i+1] == s[i+2]){
            if(s[i] == 'O'){
                cout << "East\n";
                return 0;
            }else {
                cout << "West\n";
                return 0;
            }
        }
    }
    cout << "NA\n";
    return 0;
}
