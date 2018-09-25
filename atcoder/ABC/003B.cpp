#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    string s, t, u = "atcoder";
    cin >> s >> t;

    for (int i = 0; i < s.length(); ++i) {
        if(s[i] != t[i] &&  s[i] != '@' && t[i] != '@') {
            cout << "You will lose\n";
            return 0;
        }else if (s[i] != t[i] && s[i] == '@'){
            bool flag = false;
            for (auto &&x : u) {
                if(t[i] == x) flag = true;
            }
            if(!flag) {
                cout << "You will lose\n";
                return 0;
            }
        }else if (s[i] != t[i] && t[i] == '@'){
            bool flag = false;
            for (auto &&x : u) {
                if(s[i] == x) flag = true;
            }
            if(!flag) {
                cout << "You will lose\n";
                return 0;
            }
        }
    }
    cout << "You can win\n";
    return 0;
}
