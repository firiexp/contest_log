#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    int n, k;
    string s, s1, s2;
    cin >> n >> k >> s;
    for (unsigned i = 1; i <= n-1; ++i) {
        if(s.substr(0, i) == s.substr(n-i, i)){
            s1 = s.substr(0, i);
            s2 = s.substr(i, 101);
        }
    }
    string ans = s1;
    if(s1.empty()){
        for (int i = 0; i < k; ++i) {
            ans += s;
        }
    }else{
        for (int i = 0; i < k; ++i) {
            ans += s2;
        }
    }
    cout << ans << "\n";
    return 0;
}
