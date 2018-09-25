#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string s,t;
    cin >> s >> t;
    int a = 1;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; j < s.length(); ++j) {
            if (s[(i+j)%s.length()] != t[j]) {a = 0; break;}
        }
        if (a == 1) {cout << "Yes"; return 0;}
        a = 1;
    }
    cout << "No";
    return 0;
}