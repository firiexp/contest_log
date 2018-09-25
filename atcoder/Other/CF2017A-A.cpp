#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << (s.substr(0,4) == "YAKI" ? "Yes\n" : "No\n");
    return 0;
}
