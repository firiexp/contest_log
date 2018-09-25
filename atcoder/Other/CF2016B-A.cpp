#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string s1, s2 = "CODEFESTIVAL2016";
    cin >> s1;
    int c = 0;
    for (int i = 0; i < s2.length(); ++i) {
        if(s1[i] != s2[i]) c++;
    }
    cout << c << "\n";
    return 0;
}
