#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    int a, b;
    string s;
    cin >> a >> b >> s;
    cout << ((a <= s.length() && s.length() <= b) ? "YES" : "NO") << "\n";
    return 0;
}
