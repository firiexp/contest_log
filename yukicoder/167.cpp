#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string n, m;
    int a, b = 1;
    cin >> n >> m;

    a = n.back()- '0';
    int ans = a;
    b = (stoi("10" + m.substr(m.size() >= 2? m.size()-2 : 0) ) -1 ) % 4 + 1;
    for (int i = 1; i < b; ++i) {
        ans =(ans * a)%10;
    }
    if (m == "0") ans = 1;
    cout << ans << "\n";
    return 0;
}