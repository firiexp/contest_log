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
    string s;
    cin >> s;
    string a[4] = {"dream", "dreamer", "erase", "eraser"};
    bool flag = true;
    while(flag){
        flag = false;
        int n = s.length();
        for (auto &&x : a) {
            if(s.empty() || n < x.length()) continue;
            if(s.substr(n-x.length(), x.length()) == x){
                s = s.substr(0, n-x.length());
                flag = true;
                break;
            }
        }
    }
    cout << (s.empty() ? "YES" : "NO") << "\n";
    return 0;
}
