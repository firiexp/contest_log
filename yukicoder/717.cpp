#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int n, m, aa = 0, ab = 0, ba = 0 , bb = 0;
    string s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'A') aa++;
        if(s[i] == 'B') ab++;
    }
    for (int i = 0; i < m; ++i) {
        if(t[i] == 'A') ba++;
        if(t[i] == 'B') bb++;
    }
    cout << min(aa,ba) + min(ab,bb) << "\n";
    return 0;
}