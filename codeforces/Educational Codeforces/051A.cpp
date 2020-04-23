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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        int a = 0, b = 0, c = 0;
        for (auto &&x : s) {
            if('a' <= x && x <= 'z'){
                a++;
            }
            else if('A' <= x && x <= 'Z'){
                b++;
            }
            else c++;
        }
        if(a == 0){
            if(b >= 2){
                for (auto &&x : s) {
                    if('A' <= x && x <= 'Z'){
                       x = 'a';
                       break;
                    }
                }
            }else {
                for (auto &&x : s) {
                    if('0' <= x && x <= '9'){
                        x = 'b';
                        break;
                    }
                }
            }
        }
        if(b == 0){
            if(a >= 2){
                for (auto &&x : s) {
                    if('a' <= x && x <= 'z'){
                        x = 'A';
                        break;
                    }
                }
            }else {
                for (auto &&x : s) {
                    if('0' <= x && x <= '9'){
                        x = 'B';
                        break;
                    }
                }
            }
        }
        if(c == 0){
            if(a >= 2){
                for (auto &&x : s) {
                    if('a' <= x && x <= 'z'){
                        x = '4';
                        break;
                    }
                }
            }else {
                for (auto &&x : s) {
                    if('A' <= x && x <= 'Z'){
                        x = '4';
                        break;
                    }
                }
            }
        }
        cout << s << "\n";
    }
    return 0;
}
