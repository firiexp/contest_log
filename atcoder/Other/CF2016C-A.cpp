#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 101, b = -1;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == 'C') a = min(a, i);
        if(s[i] == 'F') b = max(b, i);
    }
    cout << (a < b ? "Yes" : "No") << "\n";
    return 0;
}
