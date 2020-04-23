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
    int p = -1, q = -1;
    if(s.length() == 2){
        if(s[0] == s[1]){
            p = 1, q = 2;
        }
    }else{
        for (int i = 0; i < s.length()-2; ++i) {
            if(s[i] == s[i+1]) {
                p = i+1, q = i+2;
                break;
            }
            else if(s[i+1] == s[i+2]) {
                p = i+2, q = i+3;
                break;
            }else if(s[i] == s[i+2]) {
                p = i+1, q = i+3;
                break;
            }
        }
    }
    cout << p << " " << q << "\n";
    return 0;
}
