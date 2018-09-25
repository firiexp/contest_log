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
    int t = static_cast<int>(s.length());
    string s2, s3;
    for (int i = 0; i < t; ++i) {
        if(i%2){
            s2 += '2';
            s3 += '5';
        }else {
            s2 += '5';
            s3 += '2';
        }
    }
    int ss = 0, sss = 0, ans = 0;
    for (int i = 0; i < t; ++i) {
        if(s[i] == s2[i] || s[i] == '?') {
            ss++;
            if(ss == 1 && s2[i] == '5') ss--;
        }
        else ss = 0;
        if(s[i] == s3[i] || s[i] == '?') {
            sss++;
            if(sss == 1 && s3[i] == '5') sss--;
        }
        else sss = 0;
        ans = max({ans, ss/2*2, sss/2*2});
    }
    cout << ans << "\n";
    return 0;
}
