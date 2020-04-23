#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    array<int, 26> ok{};
    string s;
    cin >> s;
    for (auto &&i : s) ok[i-'a']++;
    cin >> s;
    int q;
    cin >> q;
    int occur = -1;
    for (int i = 0; i < s.size(); ++i) if(s[i] == '*') occur = i;
    int minlen = (int)s.size()-(~occur ? 1 : 0), n = s.size();
    while(q--){
        string t;
        cin >> t;
        int m = t.size();
        if(minlen > m){
            puts("NO");
            continue;
        }
        if(~occur){ // include *
            int good = 1;
            for (int i = 0; i < occur; ++i) {
                if(s[i] == '?') {
                    if(!ok[t[i]-'a']){
                        good = 0;
                        break;
                    }
                }else if(s[i] != t[i]){
                    good = 0;
                    break;
                }
            }
            for (int i = 1; i < n-occur; ++i) {
                if(s[n-i] == '?') {
                    if(!ok[t[m-i]-'a']){
                        good = 0;
                        break;
                    }
                }else if(s[n-i] != t[m-i]){
                    good = 0;
                    break;
                }
            }
            for (int i = occur; i < m-n+occur+1; ++i) {
                if(ok[t[i]-'a']) {
                    good = 0;
                    break;
                }
            }
            puts(good ? "YES" : "NO");
        }else {
            if(s.size() != t.size()){
                puts("NO");
                continue;
            }else {
                int good = 1;
                for (int i = 0; i < n; ++i) {
                    if(s[i] == '?') {
                        if(!ok[t[i]-'a']){
                            good = 0;
                            break;
                        }
                    }else if(s[i] != t[i]){
                        good = 0;
                        break;
                    }
                }
                puts(good ? "YES" : "NO");
            }
        }
    }
    return 0;
}