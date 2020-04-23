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
    while(cin >> s){
        int a = 0, b = 0;
        for (int i = 0; i < s.length()-2; ++i) {
            if(s[i+1] == 'O' && s[i+2] == 'I'){
                if(s[i] == s[i+2]) b++;
                else if(s[i] == 'J') a++;
            }
        }
        cout << a << "\n" << b << "\n";
    }
    return 0;
}
