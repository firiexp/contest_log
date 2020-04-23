#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;
    s = s + s;
    int m = 1, x = 1;
    for (int i = 1; i < s.length(); ++i) {
        if(s[i] == s[i-1]) x = 1;
        else x++;
        m = max(m, x);
    }
    if(m == s.length()) m /= 2;
    cout << m << "\n";
    return 0;
}
